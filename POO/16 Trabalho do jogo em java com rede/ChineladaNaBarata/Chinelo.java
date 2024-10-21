import java.awt.Graphics;
import java.awt.Image;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Chinelo {
  Image img, imgBatendo;
  /** Espaço até o centro da imagem */
  int dx = 55, dy = 140;
  /** Ancora da imagem, canto superior da imagem */
  int posX = 0, posY = 0;
  boolean batendo = false;
  /** Area onde o chinelo aparece */
  JPanel arena;

  public Chinelo(JPanel arena, int n) {
    try {
      this.arena = arena;
      img = ImageIO.read(new File("Chinelo" + (n == 1 ? "A" : "B") + ".png"));
      imgBatendo = ImageIO.read(new File("ChineloBate" + (n == 1 ? "A" : "B") + ".png"));
    } catch (IOException e) {
      JOptionPane.showMessageDialog(arena, "A imagem não pode ser carregada!\n" + e, "Erro", JOptionPane.ERROR_MESSAGE);
      System.exit(1);
    }
  }

  public void posiciona(int x, int y) {
    posX = x;
    posY = y;
    batendo = false;
    arena.repaint();
  }

  public void bate() {
    batendo = true;
    arena.repaint();
  }

  public void desenha(Graphics g) {
    if (batendo) {
      g.drawImage(imgBatendo, posX - dx, posY - dy, arena);
      batendo = false;
    } else {
      g.drawImage(img, posX - dx, posY - dy, arena);
    }
  }

}