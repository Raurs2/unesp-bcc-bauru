import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

public class Ambiente extends JPanel {
  static final int bg1 = 4;
  static final int bg2 = 5;
  static final int bg3 = 6;
  static final int bg4 = 7;
  static final int bg5 = 8;
  static final int bg6 = 9;

  int largJogo = 1800;
  int altuJogo = 900;

  JogadorDesenho jogador;
  JogadorDesenho adversario;
  Image[] img = new Image[3];

  Ambiente(JogoCliente jogo) 
  {
    carregaImagens();
    jogador = new JogadorDesenho(jogo);
    adversario = new JogadorDesenho(jogo);
    //adversario.inverte(true);
  }

  void carregaImagens() 
  {
    try 
    {
      img[bg1] = ImageIO.read(new File("img/bg/bg1.jpg"));
      img[bg2] = ImageIO.read(new File("img/bg/bg2.jpg"));
      img[bg3] = ImageIO.read(new File("img/bg/bg3.jpg"));
      img[bg4] = ImageIO.read(new File("img/bg/bg4.jpg"));
      img[bg5] = ImageIO.read(new File("img/bg/bg5.jpg"));
      img[bg6] = ImageIO.read(new File("img/bg/bg6.jpg"));
    } catch (IOException e) 
    {
      Mensagem.erroFatalExcecao(this, "A imagem não pode ser carregada!", e);
    }
  }

  public void ajustaTamanho(int largJogo, int altuJogo) 
  {
    this.largJogo = largJogo;
    this.altuJogo = altuJogo;
    setPreferredSize(new Dimension(largJogo, altuJogo));
  }

  @Override
  public void paintComponent(Graphics g) 
  {
    super.paintComponent(g);
    g.clipRect(5, 5, getWidth() - 10, getHeight() - 10);

    g.drawImage(img[FUNDO], 0, 0, largJogo, altuJogo, this);

    jogador.desenha(g);
    adversario.desenha(g);

    g.drawImage(img[ARBUSTO], 300, altuJogo - img[ARBUSTO].getHeight(this) - 10, this);
    g.drawImage(img[GRAMA], 0, 0, largJogo, altuJogo, this);

    desenhaPlacar(g);

    Toolkit.getDefaultToolkit().sync();
  }

  void desenhaPlacar(Graphics g) {
    Font f = new Font("Arial", Font.BOLD, 50);
    g.setFont(f);
    String s = jogador.pontos + " x " + adversario.pontos;
    FontMetrics fm = g.getFontMetrics();
    int x = (largJogo - fm.stringWidth(s)) / 2;
    g.drawString(s, x - 1, fm.getHeight() - 1);
    g.setColor(Color.RED);
    g.drawString(s, x + 1, fm.getHeight() + 1);
  }

}