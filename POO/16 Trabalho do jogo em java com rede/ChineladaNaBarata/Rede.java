import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

import javax.swing.JOptionPane;

public class Rede {
  Socket socket = null;
  DataInputStream is = null;
  DataOutputStream os = null;
  ChineladaNaBarata jogo;
  boolean temDados = true;

  public Rede(ChineladaNaBarata jogo, String IP, int porto) {
    this.jogo = jogo;
    try {
      socket = new Socket(IP, porto);
      os = new DataOutputStream(socket.getOutputStream());
      is = new DataInputStream(socket.getInputStream());
    } catch (UnknownHostException e) {
      JOptionPane.showMessageDialog(jogo, "Servidor não encontrado!\n   " + e, "Erro", JOptionPane.ERROR_MESSAGE);
      System.exit(0);
    } catch (IOException e) {
      JOptionPane.showMessageDialog(jogo, "Não pode trocar dados com o servidor!\n   " + e, "Erro",
          JOptionPane.ERROR_MESSAGE);
      System.exit(0);
    }
  }

  public void enviaPosicao(String tipo, int x, int y) {
    try {
      os.writeUTF(tipo);
      os.writeInt(x);
      os.writeInt(y);
    } catch (IOException e) {
      temDados = false;
    }
  }

  public void recebePlacar(Placar placar) {
    try {
      placar.ptosA = is.readInt();
      placar.ptosB = is.readInt();
    } catch (IOException e) {
      temDados = false;
    }
  }

  public boolean continua() {
    return temDados;
  }

  public String recebeTipoMsg() {
    try {
      return is.readUTF();
    } catch (IOException e) {
      temDados = false;
      return "";
    }
  }

  public void recebePosicoes(Posicao posBarata, Posicao posChineloA, Posicao posChineloB) {
    try {
      posBarata.x = is.readInt();
      posBarata.y = is.readInt();
      posChineloA.x = is.readInt();
      posChineloA.y = is.readInt();
      posChineloB.x = is.readInt();
      posChineloB.y = is.readInt();
    } catch (IOException e) {
      temDados = false;
    }
  }

  public void descarregaEnvio() {
    try {
      os.flush();
    } catch (IOException e) {
      temDados = false;
    }
  }

}