class Thread2 extends Thread {

  public static void main (String[] args) {
    new ThreadSimples().start();
    new Thread2().start();
    System.out.println("Terminando o Programa Principal");
  }

  public void run() {
    for (int i = 0; i < 10; i++) {
      try {
        sleep(500);
      } catch (InterruptedException e) {}
      System.out.println(i + " Linha Principal");
    }
  }
}

class ThreadSimples extends Thread {

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
Terminando a Linha Principal
0Outra Linha
0 Linha Principal
1Outra Linha
1 Linha Principal
2 Linha Principal
2Outra Linha
3 Linha Principal
4 Linha Principal
3Outra Linha
5 Linha Principal
6 Linha Principal
4Outra Linha
7 Linha Principal
8 Linha Principal
5Outra Linha
9 Linha Principal
6Outra Linha
7Outra Linha
8Outra Linha
9Outra Linha
Terminando a Outra Linha

*/
