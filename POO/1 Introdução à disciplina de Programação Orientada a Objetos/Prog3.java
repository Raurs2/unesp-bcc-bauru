class Pessoa {
  String nome, endereco, telefone;
  
  String leNome() {
    return nome;
  }
  
  String endereco() {
    return endereco;
  }
  
  void alteraNome(String pNome) {
    nome = pNome;
  }
  
  void atribui(String pNome, String pEndereco, String pTelefone) {
    nome = pNome;
    endereco = pEndereco;
    telefone = pTelefone;
  }
}

class PP {
  public static void main(String [] args) {
    Pessoa pessoa1 = new Pessoa();
    Pessoa pessoa2 = new Pessoa();
    pessoa1.atribui("Joao", "Rua XV", "32345678");
    pessoa2.atribui("Antonio", "Rua VII", "34567890");
    System.out.println("Nome: " + pessoa1.leNome());
    System.out.println("Nome: " + pessoa2.leNome());
  }
}

