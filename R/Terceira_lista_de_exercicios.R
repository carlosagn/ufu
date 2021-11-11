#Feito por
#Carlos Augusto Gomes Neto 11821BCC016
#Joao Pedro Deltoso Chagas 11721BCC021
#Victor Zuccolotto Borges 11811BCC034
#Vitor Santini Bessa 11821BCC010

x <- 1500

#Exercicio 1:
lancamento1 <- sample(1:6, size = x, replace = TRUE)
lancamento2 <- sample(1:6, size = x, replace = TRUE)

somaLancamentos <- lancamento1 + lancamento2
soma7ou11 <- sum(somaLancamentos == 7) || su(somaLancamento == 11)
soma7ou11/x

#Exercicio 2:
lancamento1Urna <- sample(1:6, size = x, replace = TRUE)
lancamento2Urna <- sample(1:6, size = x, replace = TRUE)

somaLancamentos2 <- lancamento1Urna + lancamento2Urna 

bolasEscolhidas <- c()

for ( i in somaLancamentos2) {
  if ( i == 2 || i == 3) {
    escolhida <- sample(c('preta','branca','vermelha'), size = 1, prob = c(8/15,1/5,4/15))
    bolasEscolhidas <- c(bolasEscolhidas,escolhida)
  }
  else if ( i == 4 || i == 5 || i == 6) {
    escolhida <- sample(c('preta','branca','vermelha'), size = 1, prob = c(1/5,1/3,7/15))
    bolasEscolhidas <- c(bolasEscolhidas,escolhida)
  }
  else if ( i == 7) {
    escolhida <- sample(c('preta','branca','vermelha'), size = 1, prob = c(4/9,1/3,2/9))
    bolasEscolhidas <- c(bolasEscolhidas,escolhida)
  }
  else {
    escolhida <- sample(c('preta','branca','vermelha'), size = 1, prob = c(2/11,1/11,8/11))
    bolasEscolhidas <- c(bolasEscolhidas,escolhida)
  }
}

bolasVermelhas <- sum(bolasEscolhidas == 'vermelha')
bolasVermelhas/x

#Exercicio 3
#Ganhar = 1
#Perder = 0
ranking <- c()
for(x in 1:10000){
  dados <-sample(1:6 ,2 ,replace = T)
  if(sum(dados) == 7 || sum(dados) == 11){
    ranking <- c(ranking,1)
  }else if(sum(dados) == 2 || sum(dados) == 3 || sum(dados) == 12){
    ranking <- c(ranking,0)
  }else{
    somaInicial <- sum(dados)
    repeat{
      dados <- sample(1:6 ,2 ,replace = T)
      if(sum(dados) == somaInicial){
        ranking <- c(ranking,1)
        break
      }else if(sum(dados) == 7){
        ranking <- c(ranking,0)
        break
      }
    }
  }
}
mean(ranking == 1)

#Exercicio 4
#cara  = 1
#coroa = 0
Dwight <- c(0,1,0)
Jim <- c(0,0,1)
ocorrencias <- c()
moeda <- c(2,2,2)

for(x in 1:10000){
  moeda <- c(moeda, sample(0:1 ,1 ,replace = T))
  ocorrencias <- c(ocorrencias, verificaVitoria(jogador1= Jim, jogador2= Dwight, sequenciaMoedas= moeda))
}


mean(ocorrencias == 1)


verificaVitoria <- function(jogador1,jogador2,sequenciaMoedas){
  UltimosDaSequencia <- c(sequenciaMoedas[length(sequenciaMoedas) - 2], sequenciaMoedas[length(sequenciaMoedas) - 1], sequenciaMoedas[length(sequenciaMoedas)])
  if(identical(jogador1,UltimosDaSequencia)){
    moeda <- c(2,2,2)
    return(1)
  }else if(identical(jogador2,UltimosDaSequencia)){
    moeda <- c(2,2,2)
    return(0)
  }
}

#Exercicio 5
#cara 1
#coroa -1
luke <- function(n){
  contador <- c()
  for(x in 1:10000){
    moeda  <- sample(-1:1, n,replace = T,prob = c(0.5,0,0.5))
    contador <- c(contador, sum(moeda) + 2)
  }
  return (contador)
}
quatro_passos <- mean(luke(n=4) == 0)
quatro_passos

seis_passos <- mean(luke(n=6) == 0)
seis_passos

dez_passos <-mean(luke(n=10) == 0)
dez_passos

vinte_passos <-mean(luke(n=20) == 0)
vinte_passos

#Exercicio 6
#A
luke2 <- function(L){
  total <- c()
  for(x in 1:1000){
    somador <- c()
    while (TRUE) {
      moeda <- sample(-1:1, 1,replace = T,prob = c(0.5,0,0.5))
      somador <- c(somador, moeda)
      if(sum(somador) + L == 20){
        moeda <- c()
        total <- c(total,20)
        break
      }else if(sum(somador) + L == 0){
        moeda <- c()
        total <- c(total,0)
        break
      }
    }
  }
  return(mean(total == 20))
}

luke2(L = 16)

#B
lukeProbs <- c()
for (i in 1:19) {
  lukeProbs <- c(lukeProbs, luke2(L = i))
}

plot(x = 1:19, y = lukeProbs)

#Exercicio 7
integral <- function(inf, sup, func) {
  nsorteados <- runif(x, inf, sup)
  rfuncao <- func(nsorteados)
  media_funcao <-(sum(rfuncao) / x)
  resultado <- abs(sup - inf) * media_funcao
  return(resultado)
}


f1 <- function(n) {
  return (1/sqrt(2*pi) * exp(-(n^2/2)))
}

f2 <- function(n) {
  return ((cos(n)) ^ 2)
}

integral(0, pi, f1)
integral(-1, 2, f2)

#Exercicio 8
probX <- c(1,5,10)
gerador <- function(n){
  return (sample(probX, n, replace = TRUE, prob = c(1/7, 2/7, 4/7)))
}

mean(gerador(n=100) == 5)

mean(gerador(n=1000) == 5)

mean(gerador(n=10000) == 5)

#Exercicio 9
f3 <- function(n){
  probx7 <- 0
  vetValeatoria <- c()
  for(i in 1:x){
    valeatoria <- runif(1,0,1)
    vetValeatoria[i] <- valeatoria
    func <- (valeatoria ^ 2+valeatoria) / 2 
    if (func < 0.7){
      probx7 <- probx7 + 1
    }
  }
  
  probx7 / x #probabilidade de x ser menor que 0,7
  mean(vetValeatoria) #esperanca
}
