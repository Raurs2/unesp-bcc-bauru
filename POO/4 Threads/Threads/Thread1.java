class Thread1 extends Thread {

  public static void main (String[] args) {
    new Thread1().start();
    new Thread1().start();
    for (int i = 0; i < 10; i++) {
      try {
        sleep(500);
      } catch (InterruptedException e) {}
      System.out.println(i + " Linha Principal");
    }
    System.out.println("Terminando a Linha Principal");
  }

  public void run() {
    for (int i = 0; i < 10; i++) {
      System.out.println(i + " Outra Linha");
      try {
        sleep(1000);
      } catch (InterruptedException e) {}
    }
    System.out.println("Terminando a Outra Linha");
  }
}

/* no video teremos:
0 Outra Linha
0 Linha Principal
1 Linha Principal
1 Outra Linha
2 Linha Principal
2 Outra Linha
3 Linha Principal
4 Linha Principal
3 Outra Linha
5 Linha Principal
6 Linha Principal
4 Outra Linha
7 Linha Principal
8 Linha Principal
5 Outra Linha
9 Linha Principal
Terminando a Linha Principal
6 Outra Linha
7 Outra Linha
8 Outra Linha
9 Outra Linha
Terminando a Outra Linha
*/
