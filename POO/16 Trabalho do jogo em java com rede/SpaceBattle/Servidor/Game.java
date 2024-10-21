import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

/*
 * Autor: Raul Alexandre Gonzalez Augusto
 * RA: 211023698 
 */

class Game
{
    static final int width = 1800;
    static final int height = 900;

    int connectedPlayers = 0;
    DataOutputStream[] os;
    DataInputStream[] is;
    Player[] players;
    int[] points = { 0, 0 };
    boolean continua = true;
    Logic logic;

    
    Game(int maxPlayers)
    {
        os = new DataOutputStream[maxPlayers];
        is = new DataInputStream[maxPlayers];
        players = new Player[maxPlayers];
    }

    public void addPlayer(Socket clientSocket) 
    {
        initPlayer(connectedPlayers, clientSocket);
        sendInitialData(connectedPlayers);
        startThreadPlayerReceive(connectedPlayers);
        connectedPlayers++;
    }

    public int maxPlayers()
    {
        return players.length;
    }

    public void initPlayer(int numPlayers, Socket clientSocket) 
    {
        try 
        {
            os[numPlayers] = new DataOutputStream(clientSocket.getOutputStream());
            is[numPlayers] = new DataInputStream(clientSocket.getInputStream());

            if (numPlayers == 0) 
            {
            players[numPlayers] = new Player(100,  height - 100);
            } else 
            {
            players[numPlayers] = new Player(width - 100, height - 100);
            }
        } catch (IOException e) {
            e.printStackTrace();
            continua = false;
        }
    }

    public void initLogic(Logic logic)
    {
        this.logic = logic;
    }

    public void start()
    {
        startThreadGameSend();
    }
    
    public void sendInitialData(int PlayersConnected) 
    {
    try 
    {
        os[PlayersConnected].writeInt(width);
        os[PlayersConnected].writeInt(height);
    } catch (IOException e) 
    {
        e.printStackTrace();
        continua = false;
    }
    }

    public void startThreadGameSend() 
    {
    new Thread(new Runnable() 
    {
        public void run() 
        {
            while (continua) 
            {
                logic.run();

                sendStatus(0);
                sendStatus(1);
                sendScore();

                enviaSituacaoInvertido(1);
                enviaSituacaoInvertido(0);
                enviaPlacarInvertido();

                forceFlush();
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

    void iniciaThreadJogadorRecebe(int numDoJogador) {
    new Thread(new Runnable() {
        int numJogadorEsperando = numDoJogador;

        public void run() {
        while (continua) {
            recebeComandosEDadosDoJogador(numJogadorEsperando);
        }
        }
    }).start();

    }

    public void recebeComandosEDadosDoJogador(int numDoJogador) {
    try {
        jogadores[numDoJogador].estado = is[numDoJogador].readInt();
        // System.out.println("estado: " + jogadores[numDoJogador].estado);
    } catch (IOException e) {
        e.printStackTrace();
        continua = false;
    }
    }

    public void sendStatus(int numDoJogador) {
    try {
        // System.out.print("pos " + jogadores[numDoJogador].x);
        os[0].writeInt(jogadores[numDoJogador].x);
        // System.out.print(" est " + jogadores[numDoJogador].estado);
        os[0].writeInt(jogadores[numDoJogador].estado);
        // System.out.print(" inv " + jogadores[numDoJogador].invertido);
        os[0].writeBoolean(jogadores[numDoJogador].invertido);
        // System.out.println(" Ok ");
    } catch (IOException e) {
        e.printStackTrace();
        continua = false;
    }
    }

    public void enviaSituacaoInvertido(int numDoJogador) {
    try {
        // System.out.print("pos " + jogadores[numDoJogador].x);
        os[1].writeInt(LARG_JOGO - jogadores[numDoJogador].x);
        // System.out.print(" est " + jogadores[numDoJogador].estado);
        os[1].writeInt(jogadores[numDoJogador].estado);
        // System.out.print(" inv " + jogadores[numDoJogador].invertido);
        os[1].writeBoolean(!jogadores[numDoJogador].invertido);
        // System.out.println(" Ok ");
    } catch (IOException e) {
        e.printStackTrace();
        continua = false;
    }
    }

    public void sendScore() {
    try {
        // System.out.print("Pt1 ");
        os[0].writeInt(jogadores[0].pontos);
        // System.out.print("Pt2 ");
        os[0].writeInt(jogadores[1].pontos);
        // System.out.println("Ok ");
    } catch (IOException e) {
        e.printStackTrace();
        continua = false;
    }
    }

    public void enviaPlacarInvertido() {
    try {
        // System.out.print("Pt1 ");
        os[1].writeInt(jogadores[1].pontos);
        // System.out.print("Pt2 ");
        os[1].writeInt(jogadores[0].pontos);
        // System.out.println("Ok ");
    } catch (IOException e) {
        e.printStackTrace();
        continua = false;
    }
    }

    void forceFlush() {
    try {
        os[0].flush();
        os[1].flush();
    } catch (IOException e) {
    }
    }

    static public void main(String[] args)
    {
        Game game = new Game();
    }
}