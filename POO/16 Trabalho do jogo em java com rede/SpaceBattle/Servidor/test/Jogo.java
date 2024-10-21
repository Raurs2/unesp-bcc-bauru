import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Jogo 
{
  static final int LARG_JOGO = 1800;
  static final int ALTU_JOGO = 900;

  int contaJogadoresConectados = 0;
  DataOutputStream[] os;
  DataInputStream[] is;
  Jogador[] jogadores;
  int[] pontos = { 0, 0 };
  boolean continua = true;
  Logica logica;

  Jogo(int numMaximoJogadores) 
  {
    os = new DataOutputStream[numMaximoJogadores];
    is = new DataInputStream[numMaximoJogadores];
    jogadores = new Jogador[numMaximoJogadores];
  }

  public void adicionaJogador(Socket clientSocket) 
  {
    iniciaJogador(contaJogadoresConectados, clientSocket);
    enviaDadosIniciais(contaJogadoresConectados);
    iniciaThreadJogadorRecebe(contaJogadoresConectados);
    contaJogadoresConectados++;
  }

  public int numMaximoJogadores() 
  {
    return jogadores.length;
  }

  public void iniciaJogador(int numJogador, Socket clientSocket) 
  {
    try 
    {
      os[numJogador] = new DataOutputStream(clientSocket.getOutputStream());
      is[numJogador] = new DataInputStream(clientSocket.getInputStream());
      if (numJogador == 0) 
      {
        jogadores[numJogador] = new Jogador(100, ALTU_JOGO - 100);
      } else 
      {
        jogadores[numJogador] = new Jogador(LARG_JOGO - 100, ALTU_JOGO - 100);
        jogadores[numJogador].inverte(true);
      }
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  public void iniciaLogica(Logica logica) 
  {
    this.logica = logica;    
  }

  public void inicia() 
  {
    iniciaThreadJogoEnvio();
  }

  public void enviaDadosIniciais(int numJogadorDestino) 
  {
    try 
    {
      os[numJogadorDestino].writeInt(LARG_JOGO);
      os[numJogadorDestino].writeInt(ALTU_JOGO);
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  public void iniciaThreadJogoEnvio() 
  {
    new Thread(new Runnable() 
    {
      public void run() 
      {
        while (continua) 
        {
          logica.executa();

          enviaSituacao(0);
          enviaSituacao(1);
          enviaPlacar();

          enviaSituacaoInvertido(1);
          enviaSituacaoInvertido(0);
          enviaPlacarInvertido();

          forcaEnvio();
          try 
          {
            Thread.sleep(200);
          } catch (InterruptedException e) 
          {
            e.printStackTrace();
          }
        }
      }
    }).start();
  }

  void iniciaThreadJogadorRecebe(int numDoJogador) 
  {
    new Thread(new Runnable() 
    {
      int numJogadorEsperando = numDoJogador;

      public void run() 
      {
        while (continua) 
        {
          recebeComandosEDadosDoJogador(numJogadorEsperando);
        }
      }
    }).start();
  }

  public void recebeComandosEDadosDoJogador(int numDoJogador) 
  {
    try 
    {
      jogadores[numDoJogador].estado = is[numDoJogador].readInt();
      // System.out.println("estado: " + jogadores[numDoJogador].estado);
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  public void enviaSituacao(int numDoJogador) 
  {
    try 
    {
      // System.out.print("pos " + jogadores[numDoJogador].x);
      os[0].writeInt(jogadores[numDoJogador].x);
      // System.out.print(" est " + jogadores[numDoJogador].estado);
      os[0].writeInt(jogadores[numDoJogador].estado);
      // System.out.print(" inv " + jogadores[numDoJogador].invertido);
      os[0].writeBoolean(jogadores[numDoJogador].invertido);
      // System.out.println(" Ok ");
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  public void enviaSituacaoInvertido(int numDoJogador) 
  {
    try 
    {
      // System.out.print("pos " + jogadores[numDoJogador].x);
      os[1].writeInt(LARG_JOGO - jogadores[numDoJogador].x);
      // System.out.print(" est " + jogadores[numDoJogador].estado);
      os[1].writeInt(jogadores[numDoJogador].estado);
      // System.out.print(" inv " + jogadores[numDoJogador].invertido);
      os[1].writeBoolean(!jogadores[numDoJogador].invertido);
      // System.out.println(" Ok ");
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  public void enviaPlacar() 
  {
    try 
    {
      // System.out.print("Pt1 ");
      os[0].writeInt(jogadores[0].pontos);
      // System.out.print("Pt2 ");
      os[0].writeInt(jogadores[1].pontos);
      // System.out.println("Ok ");
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  public void enviaPlacarInvertido() 
  {
    try 
    {
      // System.out.print("Pt1 ");
      os[1].writeInt(jogadores[1].pontos);
      // System.out.print("Pt2 ");
      os[1].writeInt(jogadores[0].pontos);
      // System.out.println("Ok ");
    } catch (IOException e) 
    {
      e.printStackTrace();
      continua = false;
    }
  }

  void forcaEnvio() 
  {
    try 
    {
      os[0].flush();
      os[1].flush();
    } catch (IOException e) { }
  }

}

