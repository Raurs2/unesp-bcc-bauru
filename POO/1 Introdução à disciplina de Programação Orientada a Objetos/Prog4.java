class Pessoa {
  String nome, end, tel;

  void inicia(String _nome, String _end, String _tel) {
    nome = _nome;
    end = _end;
    tel = _tel;
  }

  public static void main(String s[]) {
    Pessoa p = new Pessoa();
    p.inicia("Joao", "Rua XV", "32345678");
    System.out.format("Nome:     %s\n" +
                      "Endereco: %s\n" +
                      "Telefone: %s\n", p.nome, p.end, p.tel); 
  }
}
