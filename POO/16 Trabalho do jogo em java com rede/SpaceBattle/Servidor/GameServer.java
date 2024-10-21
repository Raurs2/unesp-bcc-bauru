import java.awt.Dimension;
import java.awt.Rectangle;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.NoSuchElementException;

/*
 * Autor: Raul Alexandre Gonzalez Augusto
 * RA: 211023698 
 */

public class GameServer
{
    GameServer()
    {
        //inicia servidor
        try 
        {
            ServerSocket serverSocket = new ServerSocket(12345);
        } catch (Exception e) 
        {
            System.out.println("Nao pode escutaro o porto: " + porto + ".\n" + e);
            System.exit(1);
        }

        while (true)
        {
            Game game = new Game();
            int maxPlayers = game.maxPlayers();

            for (int i = 0; i < maxPlayers; i++) 
            {
                Socket clientSocket = waitClient(this.serverSocket);
                game.addPlayer(clientSocket);
            }

            game.initLogic(new Logic(game));
            game.start();
        }
    }

    Socket waitClient(ServerSocket serverSocket)
    {
        try 
        {
            System.out.println("Esperando conexao de um jogador.");
            Socket clientSocket = serverSocket.accept();
        } catch (IOException e) 
        {
            System.out.println("Accept falhou: " + serverSocket.getLocalPort() + ".\n" + e);
            System.exit(1);
        }
        System.out.println("Accept Funcionou!");
        return this.clientSocket;
    }

    public static void main(String[] args)
    {
    new GameServer();
    }
}