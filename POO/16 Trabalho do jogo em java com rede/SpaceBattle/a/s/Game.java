import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.swing.*;
import javax.swing.text.StyledEditorKit.ForegroundAction;

import java.io.*;
import javax.imageio.*;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;

/*
 * Autor: Raul Alexandre Gonzalez Augusto
 * RA: 211023698 
 */

class Game extends JFrame
{
    Image img[] = new Image[20];

    final int p1up = 0;
    final int p1right = 1;
    final int p1left = 2;
    final int p1down = 3;

    final int bg1 = 4;
    final int bg2 = 5;
    final int bg3 = 6;
    final int bg4 = 7;
    final int bg5 = 8;
    final int bg6 = 9;

    final int meteor1 = 10;
    final int meteor2 = 11;
    final int meteor3 = 12;
    final int meteor4 = 13;

    final int p2up = 14;
    final int p2right = 15;
    final int p2left = 16;
    final int p2down = 17;

    int p1x = 0, p1y = -50, p1Sprite = p1up;
    int p2x = 1000, p2y = -50, p2Sprite = p2up;

    int moveSpeed = 20, meteorSpeed[] = new int[4];
    int meteorTrajectory[] = new int[4];

    Timer t;
    int score = 0;

    //funcao para gerar numeros aleatorios
    public int getRandomNumber(int min, int max)
    {
        return (int) ((Math.random() * (max - min)) + min);
    }

    int rand[] = new int[4];

    //Seleciona um background aleatorio
    int bgSelected = getRandomNumber(bg1, bg6);

    GameMap map = new GameMap();

    //função para gerar um retangulo
    public Rectangle getBounds(int x, int y, int width, int height)
    {
        return new Rectangle(x, y, width, height);
    }

    int mWidth[] = new int[4];
    int mHeight[] = new int[4];
    int pWidth[] = new int[2];
    int pHeight[] = new int[2];
    int py[] = new int[2];

    final int width = 1800;
    final int height = 900;


    Game()
    {
        super("Game");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        add(map);
        pack();
        setVisible(true);

        t = new Timer(100, new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                score++;

                for (int i = 0; i < 4; i++)
                {
                    //faz os meteoros voltarem a cair com velocidade aumentanda e de posicoes aleatorias
                    if (meteorTrajectory[i] >= height)
                    {
                        meteorTrajectory[i] = 0;
                        meteorSpeed[i] += getRandomNumber(0, 5);
                        moveSpeed += getRandomNumber(0, 1);

                        for (int j = 0; j < 4; j++)
                        {
                            rand[i] = getRandomNumber(0, width);
                        }
                    } else
                    {
                        meteorTrajectory[i] += meteorSpeed[i];  //senao chegou no limite da tela ele continua caindo

                        //testa se os meteoros bateram nos jogadores, se baterem o jogo acaba e mostra a pontuação
                        if (getBounds(rand[i], meteorTrajectory[i], mWidth[i], mHeight[i]).intersects(getBounds(p1x, py[0], pWidth[0], pHeight[0])))
                        {
                            JOptionPane.showMessageDialog(null, "MARCOU "+ score + " PONTOS ANTES DE MORRER");
                            System.exit(1);
                        } else if (getBounds(rand[i], meteorTrajectory[i], mWidth[i], mHeight[i]).intersects(getBounds(p2x, py[1], pWidth[1], pHeight[1])))
                        {
                            JOptionPane.showMessageDialog(null, "MARCOU "+ score + " PONTOS ANTES DE MORRER");
                            System.exit(1);
                        }
                    }
                    repaint();
                }
                repaint();
            }
        });

        t.start();

        //Tratar teclado
        addKeyListener(new KeyAdapter()
        {
            public void keyPressed(KeyEvent key)
            {
                //Esc para sair
                if (key.getKeyCode() == KeyEvent.VK_ESCAPE)
                {
                    System.exit(1);
                }

                //WASD para movimento do jogador
                if (key.getKeyCode() == KeyEvent.VK_W)
                {
                    p1Sprite = p1up;
                    p1y -= moveSpeed;
                } else if (key.getKeyCode() == KeyEvent.VK_S)
                {
                    p1Sprite = p1down;
                    p1y += moveSpeed;

                } else if (key.getKeyCode() == KeyEvent.VK_D)
                {
                    p1Sprite = p1right;
                    p1x += moveSpeed;

                }  else if (key.getKeyCode() == KeyEvent.VK_A)
                {
                    p1Sprite = p1left;
                    p1x -= moveSpeed;
                }
                repaint();
            }
        });
    }

    static public void main(String[] args)
    {
        Game game = new Game();
    }
}