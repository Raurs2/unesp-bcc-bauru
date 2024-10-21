import java.io.File;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;

public class Som {
    public static void main(String[] args) {

        try {
            while (true) {
                playSound("ado.flac");
                Thread.sleep(6000);
            }
        } catch (InterruptedException e) {
        }
    }

    public static synchronized void playSound(final String arq) {
        try {
            AudioInputStream ais = AudioSystem
                    .getAudioInputStream(new File(arq));
            Clip c = AudioSystem.getClip(AudioSystem.getMixerInfo()[1]);
            c.open(ais);
            c.start();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

}
