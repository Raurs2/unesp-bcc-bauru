import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import javax.swing.*;
import javax.swing.text.StyledEditorKit.ForegroundAction;

import java.io.*;
import javax.imageio.*;
import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;

class SpaceBattle extends JFrame
{
    Image img[] = new Image[30];

    final int p1up = 0;
    final int p1right = 1;
    final int p1ur = 2;
    final int p1dr = 3;
    final int p1left = 11;
    final int p1down = 12;
    final int p1dl = 13;
    final int p1ul = 14;

    final int bg1 = 5;
    final int bg2 = 6;
    final int bg3 = 7;
    final int bg4 = 8;
    final int bg5 = 9;
    final int bg6 = 10;

    final int meteor1 = 15;
    final int meteor2 = 16;
    final int meteor3 = 17;
    final int meteor4 = 18;

    final int p2up = 4;
    final int p2right = 19;
    final int p2ur = 20;
    final int p2dr = 21;
    final int p2left = 22;
    final int p2down = 23;
    final int p2dl = 24;
    final int p2ul = 25;

    int p1x = 0, p1y = 30, p1Sprite = p1up;
    int p2x = 1000, p2y = 30, p2Sprite = p2up;

    int bgSelected = bg1;
    
    int moveSpeed = 20, meteorSpeed[] = new int[4];
    int meteorTrajectory[] = new int[4];

    Timer t;

    public int getRandomNumber(int min, int max)
    {
        return (int) ((Math.random() * (max - min)) + min);
    }

    int rand[] = new int[4];

    GameMap map = new GameMap();

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

    class GameMap extends JPanel
    {
        GameMap()
        {
            for (int i = 0; i < 4; i++)
            {
                meteorTrajectory[i] = 0;
                meteorSpeed[i] = getRandomNumber(10, 20);
                rand[i] = getRandomNumber(0, width);
            }

            setPreferredSize(new Dimension(width, height));
            try
            {
                
                img[p1up] = ImageIO.read(new File("img/player1/p1up.png"));
                img[p1right] = ImageIO.read(new File("img/player1/p1right.png"));
                img[p1ur] = ImageIO.read(new File("img/player1/p1ur.png"));
                img[p1dr] = ImageIO.read(new File("img/player1/p1dr.png"));
                img[p1down] = ImageIO.read(new File("img/player1/p1down.png"));
                img[p1left] = ImageIO.read(new File("img/player1/p1left.png"));
                img[p1ul] = ImageIO.read(new File("img/player1/p1ul.png"));
                img[p1dl] = ImageIO.read(new File("img/player1/p1dl.png"));

                img[bg1] = ImageIO.read(new File("img/bg/bg1.jpg"));
                img[bg2] = ImageIO.read(new File("img/bg/bg2.jpg"));
                img[bg3] = ImageIO.read(new File("img/bg/bg3.jpg"));
                img[bg4] = ImageIO.read(new File("img/bg/bg4.jpg"));
                img[bg5] = ImageIO.read(new File("img/bg/bg5.jpg"));
                img[bg6] = ImageIO.read(new File("img/bg/bg6.jpg"));

                img[meteor1] = ImageIO.read(new File("img/meteor/meteor1.png"));
                img[meteor2] = ImageIO.read(new File("img/meteor/meteor2.png"));
                img[meteor3] = ImageIO.read(new File("img/meteor/meteor3.png"));
                img[meteor4] = ImageIO.read(new File("img/meteor/meteor4.png"));

                img[p2up] = ImageIO.read(new File("img/player2/p2up.png"));
                img[p2right] = ImageIO.read(new File("img/player2/p2right.png"));
                img[p2ur] = ImageIO.read(new File("img/player2/p2ur.png"));
                img[p2dr] = ImageIO.read(new File("img/player2/p2dr.png"));
                img[p2down] = ImageIO.read(new File("img/player2/p2down.png"));
                img[p2left] = ImageIO.read(new File("img/player2/p2left.png"));
                img[p2ul] = ImageIO.read(new File("img/player2/p2ul.png"));
                img[p2dl] = ImageIO.read(new File("img/player2/p2dl.png"));
            } catch (IOException e)
            {
                JOptionPane.showMessageDialog(this, "A imagem não pode ser carregada!\n" + e, "Erro", JOptionPane.ERROR_MESSAGE);
                System.exit(1);
            }
        }

        public void paintComponent(Graphics g)
        {
            super.paintComponent(g);

            g.drawImage(img[bgSelected], 0, 0, getSize().width, getSize().height, this);

            g.drawImage(img[p1Sprite], p1x, getSize().height-img[p1Sprite].getHeight(this) + p1y, this);
            g.drawImage(img[p2Sprite], p2x, getSize().height-img[p2Sprite].getHeight(this) + p2y, this);
            
            g.drawImage(img[meteor1], rand[0], meteorTrajectory[0], this);
            g.drawImage(img[meteor2], rand[1], meteorTrajectory[1], this);
            g.drawImage(img[meteor3], rand[2], meteorTrajectory[2], this);
            g.drawImage(img[meteor4], rand[3], meteorTrajectory[3], this);

            mHeight[0] = img[meteor1].getHeight(this);
            mHeight[1] = img[meteor2].getHeight(this);
            mHeight[2] = img[meteor3].getHeight(this);
            mHeight[3] = img[meteor4].getHeight(this);

            mWidth[0] = img[meteor1].getWidth(this);
            mWidth[1] = img[meteor2].getWidth(this);
            mWidth[2] = img[meteor3].getWidth(this);
            mWidth[3] = img[meteor4].getWidth(this);
            
            pHeight[0] = img[p1Sprite].getHeight(this);
            pHeight[1] = img[p2Sprite].getHeight(this);

            pWidth[0] = img[p1Sprite].getWidth(this);
            pWidth[1] = img[p2Sprite].getWidth(this);

            py[0] = getSize().height-img[p1Sprite].getHeight(this) + p1y;
            py[1] = getSize().height-img[p2Sprite].getHeight(this) + p2y;

            Toolkit.getDefaultToolkit().sync();
        }
    }

    SpaceBattle()
    {
        super("SpaceBattle");

        //fullscreen mode
        /* 
        GraphicsEnvironment graphics = GraphicsEnvironment.getLocalGraphicsEnvironment();
        GraphicsDevice device = graphics.getDefaultScreenDevice();
        device.setFullScreenWindow(this);
        */

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        /*
        JComboBox bgm = new JComboBox();
        bgm.addItem("Otaku");
        bgm.addItem("Roski");
        bgm.addItem("ToHo");

        JComboBox bg = new JComboBox();
        bg.addItem("1");
        bg.addItem("2");
        bg.addItem("3");
        bg.addItem("4");
        bg.addItem("5");
        bg.addItem("6");


        JRadioButton bgm1 = new JRadioButton("1");
        JRadioButton bgm2 = new JRadioButton("2");
        JRadioButton bgm3 = new JRadioButton("3");

        ButtonGroup bgm = new ButtonGroup();
        bgm.add(bgm1);
        bgm.add(bgm2);
        bgm.add(bgm3);

        JRadioButton bg1 = new JRadioButton("1");
        JRadioButton bg2 = new JRadioButton("2");
        JRadioButton bg3 = new JRadioButton("3");

        ButtonGroup bg = new ButtonGroup();
        bg.add(bg1);
        bg.add(bg2);
        bg.add(bg3);

        JButton bStart = new JButton("Play");
        
        JPanel menu = new JPanel();
        menu.add(new JLabel("BGM: "));
        menu.add(bgm1);
        menu.add(bgm2);
        menu.add(bgm3);
        menu.add(new JLabel("BG: "));
        menu.add(bg1);
        menu.add(bg2);
        menu.add(bg3);
        menu.add(bStart);

        add(menu, BorderLayout.NORTH);*/
        add(map, BorderLayout.SOUTH);

        pack();
        setVisible(true);

        t = new Timer(100, new ActionListener()
        {
            public void actionPerformed(ActionEvent ae)
            {
                for (int i = 0; i < 4; i++)
                {
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
                        meteorTrajectory[i] += meteorSpeed[i];  
                        if (getBounds(rand[i], meteorTrajectory[i], mWidth[i], mHeight[i]).intersects(getBounds(p1x, py[0], pWidth[0], pHeight[0])))
                        {
                            JOptionPane.showMessageDialog(null, "MORREU!");
                            System.exit(1);
                        } else if (getBounds(rand[i], meteorTrajectory[i], mWidth[i], mHeight[i]).intersects(getBounds(p2x, py[1], pWidth[1], pHeight[1])))
                        {
                            JOptionPane.showMessageDialog(null, "MORREU!");
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
                if (key.getKeyCode() == KeyEvent.VK_ESCAPE)
                {
                    System.exit(1);
                }

                /*if (key.getKeyCode() == KeyEvent.VK_W && key.getKeyCode() == KeyEvent.VK_D)
                {
                    p1Sprite = p1ur;
                    p1y -= moveSpeed;
                    p1x += moveSpeed;
                } else if (key.getKeyCode() == KeyEvent.VK_W && key.getKeyCode() == KeyEvent.VK_A)
                {
                    p1Sprite = p1ul;
                    p1y -= moveSpeed;
                    p1x -= moveSpeed;
                } else if (key.getKeyCode() == KeyEvent.VK_S && key.getKeyCode() == KeyEvent.VK_D)
                {
                    p1Sprite = p1dr;
                    p1y += moveSpeed;
                    p1x += moveSpeed;
                } 
                else if (key.getKeyCode() == KeyEvent.VK_S && key.getKeyCode() == KeyEvent.VK_A)
                {
                    p1Sprite = p1dl;
                    p1y += moveSpeed;
                    p1x -= moveSpeed;
                } 
                else*/ if (key.getKeyCode() == KeyEvent.VK_W)
                {
                    System.out.println(pWidth[0]);
                    System.out.println(pHeight[0]);
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

        /* 
        //Fechar menu e iniciar jogo
        bStart.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                menu.removeAll();
                remove(menu);
                revalidate();
                repaint();
                t.start();
            }
        });*/
    }

    static public void main(String[] args)
    {
        SpaceBattle game = new SpaceBattle();
    }
}