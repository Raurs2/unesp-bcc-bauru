import java.awt.Dimension;
import java.awt.Rectangle;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.NoSuchElementException;

public class JogoServidor {
  
  JogoServidor() {
    ServerSocket serverSocket;
    serverSocket = iniciaServidor(12345);

    while (true) {
      Jogo jogo = new Jogo();
      int numMaximoJogadores = jogo.numMaximoJogadores();
      for (int i = 0; i < numMaximoJogadores; i++) {
        Socket clientSocket = esperaCliente(serverSocket);
        jogo.adicionaJogador(clientSocket);
      }
      jogo.iniciaLogica(new Logica(jogo));
      jogo.inicia();
    }
  }

  ServerSocket iniciaServidor(int porto) {
    ServerSocket serverSocket = null;
    try {
      serverSocket = new ServerSocket(porto);
    } catch (IOException e) {
      System.out.println("Nao pode escutaro o porto: " + porto + ".\n" + e);
      System.exit(1);
    }
    return serverSocket;
  }

  Socket esperaCliente(ServerSocket serverSocket) {
    Socket clientSocket = null;
    try {
      System.out.println("Esperando conexao de um jogador.");
      clientSocket = serverSocket.accept();
    } catch (IOException e) {
      System.out.println("Accept falhou: " + serverSocket.getLocalPort() + ".\n" + e);
      System.exit(1);
    }
    System.out.println("Accept Funcionou!");
    return clientSocket;
  }
  
  public static void main(String[] args) {
    new JogoServidor();
  }
}

class Jogo {

  Socket clientSocket;
  DataOutputStream[] os = new DataOutputStream[2];
  boolean continua = true;
  Logica logica;
  int x, y;
  boolean clienteVivo[] = { true, true };

  int contaJogadoresConectados = 0;

  public void adicionaJogador(Socket clientSocket) {
    this.clientSocket = clientSocket;
    int numDoJogador = contaJogadoresConectados++;
    try {
      os[numDoJogador] = new DataOutputStream(clientSocket.getOutputStream());
    } catch (IOException e) {
      continua = false;
      e.printStackTrace();
    }
    iniciaThreadDoCliente(clientSocket, numDoJogador);
  }

  void iniciaThreadDoCliente(Socket clientSocket, int numDoJogador) {
    int numJogador = numDoJogador;
    int numAdversario = 1 - numDoJogador;
    new Thread() {
      // vai existir uma thread para cada cliente
      public void run() {
        try {
          DataInputStream is = new DataInputStream(clientSocket.getInputStream());
          String tipo;

          do {
            tipo = is.readUTF();
            switch (tipo) {
              case "MP":
                if (logica.acertouChinelada(numJogador, is.readInt(), is.readInt())) {
                  synchronized (logica) {
                    enviaTipo("ACERTOU", numJogador);
                    enviaTipo("ADVERSARIO ACERTOU", numAdversario);
                    enviaPlacar(numJogador);
                    enviaPlacar(numAdversario);
                  }
                  descarregaEnvio();
                  sleep(1000);
                } else {
                  synchronized (logica) {
                    enviaTipo("ERROU", numJogador);
                    enviaTipo("ADVERSARIO ERROU", numAdversario);
                  }
                }
                break;
              case "MM":
                logica.moveChinelo(numJogador, is.readInt(), is.readInt());
                synchronized (logica) {
                  enviaTipo("SOH_COORDENADAS", numJogador);
                  enviaTipo("SOH_COORDENADAS", numAdversario);
                }
                break;
            }
            descarregaEnvio();
          } while (clienteVivo[numJogador] && clienteVivo[numAdversario]);

          os[numJogador].close();
          is.close();
          clientSocket.close();
        } catch (IOException e) {
          try {
            clientSocket.close();
          } catch (IOException e1) {
            e1.printStackTrace();
          }
        } catch (NoSuchElementException e) {
        } catch (InterruptedException e) {
        }
      }
    }.start();
  }

  public int numMaximoJogadores() {
    return 2;
  }

  public void iniciaLogica(Logica logica) {
    this.logica = logica;
  }

  public void inicia() {
    enviaContagemRegressiva();
    logica.jogando = true;
    logica.executa();
  }

  public void enviaContagemRegressiva() {
    int numJogador = 0;
    int numAdversario = 1 - numJogador;
    try {
      envia("3", numJogador);
      envia("3", numAdversario);
      Thread.sleep(1000);
      envia("2", numJogador);
      envia("2", numAdversario);
      Thread.sleep(1000);
      envia("1", numJogador);
      envia("1", numAdversario);
      Thread.sleep(1000);
    } catch (InterruptedException e) {
    }
  }

  void descarregaEnvio() {
    try {
      os[0].flush();
      os[1].flush();
    } catch (IOException e) {
    }
  }

  void envia(String s, int numJogador) {
    int numAdversario = 1 - numJogador;
    if (clienteVivo[numJogador]) {
      try {
        os[numJogador].writeUTF(s);
      } catch (IOException e) {
        clienteVivo[numJogador] = false;
        enviaTipo("GANHOU", numAdversario);
        enviaPlacar(numAdversario);
      }
    }
  }

  void envia(int i, int numJogador) {
    int numAdversario = 1 - numJogador;
    if (clienteVivo[numJogador]) {
      try {
        os[numJogador].writeInt(i);
      } catch (IOException e) {
        clienteVivo[numJogador] = false;
        enviaTipo("GANHOU", numAdversario);
        enviaPlacar(numAdversario);
      }
    }
  }

  void enviaTipo(String tipo, int numJogador) {
    envia(tipo, numJogador);
    enviaPosicoes(numJogador);
    descarregaEnvio();
  }

  void enviaPlacar(int numJogador) {
    int numAdversario = 1 - numJogador; 
    envia(logica.ptos[numJogador], numJogador);
    envia(logica.ptos[numAdversario], numJogador);
  }

  void enviaPosicao(Posicao p, int numJogador) {
    envia(p.x, numJogador);
    envia(p.y, numJogador);
  }

  void enviaPosicoes(int numJogador) {
    int numAdversario = 1 - numJogador; 
    enviaPosicao(logica.posicaoBarata(), numJogador);
    enviaPosicao(logica.posicaoChinelo(numJogador), numJogador);
    enviaPosicao(logica.posicaoChinelo(numAdversario), numJogador);
  }
}

class Logica {
  /**
   * Define a área sensível da barata a cheneladas Os valores 155, 55 dependem da
   * imagem usada no cliente. Os valores -155 e -55 foram colocados para o
   * retangulo ficar fora da área de jogo.
   */
  public Rectangle areaSensivelDaBarata = new Rectangle(-155, 55, 155, 55);
  /** Define o tamanho da área de jogo */
  final Dimension tamAreaJogo = new Dimension(800, 600);
  /** Posições dos dois chinelos */
  public Posicao posChinelo[] = { new Posicao(0, 0), new Posicao(0, 0) };
  /** Placar do jogo */
  public int[] ptos = new int[2];
  /** Verdadeiro se o jogo estiver acontecendo */
  public boolean jogando = false;
  /** Verdadeiro se a bara estiver viva */
  boolean barataViva = false;
  Jogo jogo;

  Logica(Jogo jogo) {
    this.jogo = jogo;
  }

  public boolean acertouChinelada(int numJogador, int x, int y) {
    if (areaSensivelDaBarata.contains(x, y)) {
      barataViva = false;
      ptos[numJogador]++;
      return true;
    }
    return false;
  }

  public void moveChinelo(int numJogador, int x, int y) {
    posChinelo[numJogador].x = x;
    posChinelo[numJogador].y = y;
  }

  public Posicao posicaoBarata() {
    return new Posicao(areaSensivelDaBarata.x, areaSensivelDaBarata.y);
  }

  public Posicao posicaoChinelo(int numJogador) {
    return posChinelo[numJogador];
  }

  public void novaPosicaoDaBarata() {
    // Colca o bichinho em uma posição aleatória
    barataViva = true;
    areaSensivelDaBarata.x = (int) (Math.random() * (tamAreaJogo.width - areaSensivelDaBarata.width));
    areaSensivelDaBarata.y = (int) (Math.random() * (tamAreaJogo.height - areaSensivelDaBarata.height));
  }

  public void executa() {
    iniciaTemporizador();
  }

  public void iniciaTemporizador() {
    new Thread() {
      public void run() {
        while (jogo.clienteVivo[0] && jogo.clienteVivo[1]) {
          try {
            temporizadorLogica();
            sleep(1000);
          } catch (InterruptedException e) {
          }
        }
      }
    }.start();
  }

  public void temporizadorLogica() {
    novaPosicaoDaBarata();
    synchronized (this) {
      jogo.enviaTipo("SOH_COORDENADAS", 0);
      jogo.enviaTipo("SOH_COORDENADAS", 1);
      jogo.descarregaEnvio();
    }
  }

}
