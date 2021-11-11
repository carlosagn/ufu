/**
 *
 * @author Victor Borges Zuccolotto
 */
    public class Produto implements Comparable{
        //atributos mudar nomes
        private String descricao;
        private double precouni;
        private int quant;
        private String codigo = new String();
        public Produto(String codigo) throws Exception{
            setCodigoBarra(codigo);

        }
        public void setPreco(double precouni) {
            this.precouni = precouni;
        }

        public void setDescricao(String descricao) {
            this.descricao = descricao;
        }
        private void setCodigoBarra(String codigo) throws Exception{
            int cnt;
            if(codigo.length()!= 6){
                throw new Exception ("Sao necessarios 6 dígitos");
            }
            int valor = Integer.parseInt(codigo);
            calculaDV(codigo);
            this.codigo = codigo;
        }
        private void calculaDV(String a)throws Exception{
            char aux;

            char[] aux1 = new char[10];
            int cnt = 2,soma = 0;
            for(int i = 0; i <5 ;i++){
                aux = a.charAt(i);

                int b=Character.getNumericValue(aux);
                int c = cnt*b;
                soma += (c/10)+(c%10);
                if(cnt == 1)
                    cnt = 2;
                else
                    cnt = 1;
            }
            int modulo = (soma%10);
            modulo = 10-modulo;

            if(Character.getNumericValue(a.charAt(5))!=modulo){
                throw new Exception("Invalido");
            }


        }
        public Boolean equals(Produto b){
            return this.codigo.equals(b.codigo);
        }
        @Override
        public String toString(){

            return "=======================\n" + "Descrição: " + this.descricao + "\nCodigo: " + this.codigo + "\nPreço: "+ Double.toString(this.precouni) + "\nQuantidade: " + Integer.toString(this.quant);
        }
        @Override
        public int compareTo(Object c) {

            if(this.precouni < ((Produto)c).precouni)
                return 1;
            else if(this.precouni > ((Produto)c).precouni)
                return -1;
            return 0;
        }
    }