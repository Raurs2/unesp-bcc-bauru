import java.awt.Graphics;
import java.awt.Image;
import java.awt.Rectangle;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Barata {
  Image img, imgEsmagada;
  /** Espaço até a área sensível na imagem */
  final int dx = 20, dy = 90;
  /**
   * Ancora da imagem, canto superior da área sensível. Os valores iniciais de
   * -155 e -55 são para a área sensivel ficar fora da área de jogo
   */
  int posX = -155, posY = -55;
  /** Define a área sensível a cheneladas */
  Rectangle areaSensivel = new Rectangle(posX, posY, 155, 55);
  /** A barata está visivel? */
  boolean visivel = false;
  /** A barata está esmagada? */
  boolean barataEsmagada = false;
  /** Area onde a barata aparece */
  JPanel arena;

  public Barata(JPanel arena) {
    try {
      arena = this.arena;
      img = ImageIO.read(new File("Barata.png"));
      imgEsmagada = ImageIO.read(new File("BarataEsmagada.png"));
    } catch (IOException e) {
      JOptionPane.showMessageDialog(arena, "A imagem não pode ser carregada!\n" + e, "Erro", JOptionPane.ERROR_MESSAGE);
      System.exit(1);
    }
  }

  public void aparece(int x, int y) {
    posX = x;
    posY = y;
    areaSensivel.setLocation(posX, posY);
    visivel = true;
  }

  public void esconde() {
    visivel = false;
  }

  public boolean acertou(int x, int y) {
    if (visivel) {
      return areaSensivel.contains(x, y);
    }
    return false;
  }

  public void esmagada(boolean estado) {
    barataEsmagada = estado;
  }

  public void desenha(Graphics g) {
    if (visivel) {
      if (barataEsmagada) {
        g.drawImage(imgEsmagada, posX - dx, posY - dy, arena);
      } else {
        g.drawImage(img, posX - dx, posY - dy, arena);
      }
    }
  }
}