import java.awt.Rectangle;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;

public class JogoCliente extends JFrame 
{
  Rectangle[] rect;
  Rede rede = new Rede();
  Ambiente ambiente;

  JogoCliente() 
  {
    super("SpaceBattle");
    ambiente = new Ambiente(this);
    rede.recebeDadosIniciais(ambiente);
    
    iniciaJanela();
    tratamentoTeclas();
    controleDoJogo();
  }

  void iniciaJanela() 
  {    
    add(ambiente);
    pack();
    setResizable(false);
    setVisible(true);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
  }
  
  void tratamentoTeclas() 
  {
    addKeyListener(new KeyAdapter() 
    {
      public void keyPressed(KeyEvent e) 
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
      }
    });
  }
  
  void controleDoJogo() 
  {
    new Thread(new Runnable() 
    {
      public void run() 
      {
        while (true) 
        {
          rede.recebeSituacao(ambiente.jogador);
          rede.recebeSituacao(ambiente.adversario);
          rede.recebePlacar(ambiente);
          ambiente.repaint();
        }
      }
    }).start();
  }
  
  static public void main(String[] args) 
  {
    new JogoCliente();
  }
}
