import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class JogoServidor 
{

  JogoServidor() 
  {
    ServerSocket serverSocket;

    serverSocket = iniciaServidor(12345);

    while (true) 
    {
      Jogo jogo = new Jogo(2);
      int numMaximoJogadores = jogo.numMaximoJogadores();
      for (int i = 0; i < numMaximoJogadores; i++) 
      {
        Socket clientSocket = esperaCliente(serverSocket);
        jogo.adicionaJogador(clientSocket);
      }
      jogo.iniciaLogica(new Logica(jogo));
      jogo.inicia();
    }
  }

  ServerSocket iniciaServidor(int porto) 
  {
    ServerSocket serverSocket = null;
    try 
    {
      serverSocket = new ServerSocket(porto);
    } catch (IOException e) 
    {
      System.out.println("Nao pode escutaro o porto: " + porto + ".\n" + e);
      System.exit(1);
    }
    return serverSocket;
  }

  Socket esperaCliente(ServerSocket serverSocket) 
  {
    Socket clientSocket = null;
    try 
    {
      System.out.println("Esperando conexao de um jogador.");
      clientSocket = serverSocket.accept();
    } catch (IOException e) 
    {
      System.out.println("Accept falhou: " + serverSocket.getLocalPort() + ".\n" + e);
      System.exit(1);
    }
    System.out.println("Accept Funcionou!");
    return clientSocket;
  }
  
  public static void main(String[] args) 
  {
    new JogoServidor();
  }
}
