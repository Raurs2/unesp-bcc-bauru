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
  final int bg1 = 4;
  final int bg2 = 5;
  final int bg3 = 6;
  final int bg4 = 7;
  final int bg5 = 8;
  final int bg6 = 9;

  int largJogo = 1800;
  int altuJogo = 900;

  JogadorDesenho jogador;
  JogadorDesenho adversario;
  Meteoro[] meteoro = new Meteoro[4];
  Image[] imagens = new Image[20];

  Ambiente(JogoCliente jogo) {
    carregaImagens();
    jogador = new JogadorDesenho(jogo);
    adversario = new JogadorDesenho(jogo);
  }

  void carregaImagens() {
    try {
      img[bg1] = ImageIO.read(new File("img/bg/bg1.jpg"));
      img[bg2] = ImageIO.read(new File("img/bg/bg2.jpg"));
      img[bg3] = ImageIO.read(new File("img/bg/bg3.jpg"));
      img[bg4] = ImageIO.read(new File("img/bg/bg4.jpg"));
      img[bg5] = ImageIO.read(new File("img/bg/bg5.jpg"));
      img[bg6] = ImageIO.read(new File("img/bg/bg6.jpg"));
    } catch (IOException e) {
      Mensagem.erroFatalExcecao(this, "A imagem não pode ser carregada!", e);
    }
  }

  public void ajustaTamanho(int largJogo, int altuJogo) {
    this.largJogo = largJogo;
    this.altuJogo = altuJogo;
    setPreferredSize(new Dimension(largJogo, altuJogo));
  }

  int bgSelected = getRandomNumber(bg1, bg6);

  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);

    g.drawImage(img[bgSelected], 0, 0, getSize().width, getSize().height, this);

    jogador.desenha(g);
    adversario.desenha(g);

    Toolkit.getDefaultToolkit().sync();
  }
}