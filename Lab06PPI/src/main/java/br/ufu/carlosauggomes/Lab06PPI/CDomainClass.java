package br.ufu.carlosauggomes.Lab06PPI;
import java.math.BigInteger;
import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.Pattern;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.format.annotation.DateTimeFormat.ISO;



@Entity
@Table(name = "buy")
public class CDomainClass {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    Long id;
    
    @DateTimeFormat(iso=ISO.DATE)
    Date data;
    
    @Pattern(regexp = "\\d{5}-\\d{3}")
    String cep;
    
    @Max(1)
    @Min(30)
    BigInteger valor;


    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Date getData() {
        return data;
    }

    public void setData(Date data) {
        this.data = data;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public BigInteger getValor() {
        return valor;
    }

    public void setValor(BigInteger valor) {
        this.valor = valor;
    }

    public CDomainClass() {
    	
    }
    
    @Override
    public String toString() {
    	// TODO Auto-generated method stub
    	return cep + " " + data + " " + valor ;
    }
}