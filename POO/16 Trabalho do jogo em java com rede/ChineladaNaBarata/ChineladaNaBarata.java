import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class AreaJogo extends JPanel {
  ChineladaNaBarata jogo;
  Barata barata = new Barata(this);
  Chinelo chineloA = new Chinelo(this, 1);
  Chinelo chineloB = new Chinelo(this, 2);
  Rede rede;
  boolean jogoIniciado = false;

  AreaJogo(ChineladaNaBarata jogo, Rede rede) {
    this.jogo = jogo;
    this.rede = rede;
    setPreferredSize(new Dimension(800, 600));

    tratamentoDoCliqueDoMouse();
    tratamentoDoMovimentoDoMouse();
    moveOBichinho();
  }

  void tratamentoDoCliqueDoMouse() {
    addMouseListener(new MouseAdapter() {
      public void mousePressed(MouseEvent me) {
        if (jogoIniciado) {
          rede.enviaPosicao("MP", me.getX(), me.getY());
          rede.descarregaEnvio();
        } else {
          chineloA.bate();
        }
      }
    });
  }

  void tratamentoDoMovimentoDoMouse() {
    addMouseMotionListener(new MouseMotionAdapter() {
      public void mouseMoved(MouseEvent me) {
        if (jogoIniciado) {
          rede.enviaPosicao("MM", me.getX(), me.getY());
          rede.descarregaEnvio();
        } else {
          chineloA.posiciona(me.getX(), me.getY());
        }
      }
    });
  }

  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    barata.desenha(g);
    Rectangle rect = barata.areaSensivel;
    g.drawRect(rect.x, rect.y, rect.width, rect.height);
    chineloA.desenha(g);
    if (jogoIniciado) {
      chineloB.desenha(g);
    }
    Toolkit.getDefaultToolkit().sync();
  }

  public void recebeContagemRegressiva(Placar placar) {
    jogo.alteraPlacar("Começa em 3s  ", placar);
    rede.recebeTipoMsg();
    jogo.alteraPlacar("Começa em 2s  ", placar);
    rede.recebeTipoMsg();
    jogo.alteraPlacar("Começa em 1s  ", placar);
    rede.recebeTipoMsg();
    jogo.alteraPlacar(placar);
  }

  void moveOBichinho() {
    new Thread() {
      Posicao posBarata = new Posicao(0, 0);
      Posicao posChineloA = new Posicao(0, 0);
      Posicao posChineloB = new Posicao(0, 0);
      Placar placar = jogo.placar();

      public void run() {
        recebeContagemRegressiva(placar);

        jogoIniciado = true;

        while (rede.continua()) {
          String tipo = rede.recebeTipoMsg();
          rede.recebePosicoes(posBarata, posChineloA, posChineloB);
          switch (tipo) {
          case "ACERTOU":
            chineloA.bate();
            barata.esmagada(true);
            rede.recebePlacar(placar);
            jogo.alteraPlacar(placar);
            break;
          case "ADVERSARIO ACERTOU":
            chineloB.bate();
            barata.esmagada(true);
            rede.recebePlacar(placar);
            jogo.alteraPlacar(placar);
            break;
          case "ERROU":
            chineloA.bate();
            break;
          case "ADVERSARIO ERROU":
            chineloB.bate();
            break;
          case "PERDEU":
            chineloB.bate();
            break;
          case "GANHOU":
            rede.recebePlacar(placar);
            jogo.alteraPlacar("Você Ganhou!  ", placar);
            break;
          case "ADVERSARIO GANHOU":
            rede.recebePlacar(placar);
            jogo.alteraPlacar("Você Perdeu!  ", placar);
            break;
          case "SOH_COORDENADAS":
            barata.aparece(posBarata.x, posBarata.y);
            chineloA.posiciona(posChineloA.x, posChineloA.y);
            chineloB.posiciona(posChineloB.x, posChineloB.y);
            barata.esmagada(false);
            //~ repaint();
            break;
          }
          repaint();
        }
      }
    } .start();
  }

}


public class ChineladaNaBarata extends JFrame {
  Placar placar = new Placar(0, 0);
  JLabel lPlacar = new JLabel("", JLabel.CENTER);
  Rede rede = new Rede(this, "127.0.0.1", 12345);
  AreaJogo a = new AreaJogo(this, rede);

  public ChineladaNaBarata() {
    super("Chinelada na Barata");
    alteraPlacar(new Placar(0, 0));
    add(lPlacar, BorderLayout.NORTH);
    add(a, BorderLayout.CENTER);
    pack();
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }

  public void alteraPlacar(String ganhador, Placar p) {
    lPlacar.setText(ganhador + "Eu: " + placar.ptosA + " x Adversário: " + placar.ptosB);
  }

  public void alteraPlacar(Placar p) {
    placar = p;
    lPlacar.setText("Eu: " + p.ptosA + " x Adversário: " + p.ptosB);
  }

  public Placar placar() {
    return placar;
  }

  public static void main(String[] args) {
    new ChineladaNaBarata();
  }
}
