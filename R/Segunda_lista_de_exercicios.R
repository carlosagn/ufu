#Feito por:
#Carlos Augusto Gomes Neto 11821BCC016
#Victor Borges Zuccolotto 11811BCC034
#Joao Pedro Deltoso Chagas 11721BCC021
#Vitor Santini Bessa 11821BCC010

#Exercicio 1
#a
vetor1 <- seq(1,20)
vetor1

#b
vetor2 <- seq(20,1)
vetor2

#c
vetorAux1 <- c(vetor1,vetor2)

vetor3 <- vetorAux1[-20]
vetor3

#d
vetorAux5 <- seq(1,36,3)
vetorAux5

vetorAux6 <- seq(3,36,3)
vetorAux6

vetor4 <- (0.1^vetorAux5) * (0.2^vetorAux6)
vetor4

#e
rep(c(4,6,3),times=10)

#f
vetorAux3 <- rep(c(4,6,3),times=10)

vetor5 <- c(vetorAux3,4)
vetor5

#Exercicio 2
vetorAux7 <- seq(3, 6, 0.1)
vetor6 <- exp(vetorAux7)*cos(vetorAux7)
vetor6

#Exercicio 3
#a
seq1 <- 10:100
vetor7 <- sum(seq1^3 + (4*(seq1^2)))
vetor7

#b
seq2 <- 10:25
vetor8 <- sum(((2^seq2)/seq2) + ((3^seq2)/(seq2^2)))
vetor8

#Exercicio 4
xVec <- sample(0:999, 250, replace=T)
yVec <- sample(0:999, 250, replace=T)

#a
for ( i in 1:250) {
  if ( xVec[i] %% 2 != 0) {
    vetor9 <- c(vetor9,xVec[i])
  }
}
vetor9

#b
for ( x in 1:249) {
  for ( y in 2:250) 
    vetor10[x] <- yVec[y] - xVec[x]
}
vetor10

#c
for ( x in 1:249) {
  for ( y in 2:250)
    vetor11[x] <- sin(yVec[y])/cos(xVec[x])
}
vetor11

#d
for (i in 1:248) {
  vetor12<- c (vetor12, xVec[i] + (2*xVec[i+1]) - xVec[i+2])
}
vetor12

#e
vetor13 <- NULL
for (i in 1:249) {
  vetor13 <- c(vetor13, (exp(- xVec[i] + 1)) / (xVec[i] + 10))
}
sum(vetor13)

#Exercicio 5
#a
indicesY <- which(yVec > 600)
indicesY

#b
valoresY <- yVec[yVec > 600]
valoresY

#c
for ( i in 1:length(indicesY)) {
  valoresX[i] <- xVec[i]
}
valoresX

#d
vetor14 <- (abs(xVec - mean(xVec)))^(1/2)
vetor14


#e
length(yVec[yVec >= max(yVec) - 200])

#f
length(xVec[xVec %% 2 == 0])

#g
yvecSort <- sort(yVec);
xvecSort <- NULL;
for (i in 1:250) {
  pos <- match(yvecSort[i],yVec);
  xvecSort <- c(xvecSort, xVec[pos]);
} 
xvecSort

#h
vetor15 <- NULL
for (i in seq(1, 250, 3)) {
  vetor15 <- c(vetor15, yVec[i])
}
vetor15

#Exercicio 6
num.impar <- function(v) {
  c <- 0
  for (i in 1:length(v)) {
    if (v[i] %% 2 != 0)
      c <- c + 1
  }
  return (c)
}

num.impar(v = vetor1)

num.impar2 <- function(v) {
  return (length(which( v %% 2 != 0)))
}

num.impar2(v = vetor1)

#Exercicio 7
fibonacci2 <- function(n){
  if(n == 0)
    return(0)
  if(n == 1)
    return(1)
  return(fibonacci2(n-1) + fibonacci2(n-2))
}

fibonacci <- function(n){
  vetorFibo <- c()
  for (x in 0:n) {
    vetorFibo <- c(vetorFibo,fibonacci2(n-x))
  }
  return (sort(vetorFibo))
}

fibonacci(n = 10)

#Exercicio 8
#cara 1
#coroa 0

tamanho.seq <- function(p){
  moeda <- 1
  vetorTotal <- c()
  for(i in 1:100){
    somador <- 0
    for(j in 1:100){
      moeda<- sample(0:1, 1, replace=T, prob = c(1-p,p))
      if(moeda != 0)
        somador <- somador + 1
    }
    vetorTotal <- c(vetorTotal, somador)
  }
  return(max(vetorTotal))
}

tamanho.seq(p = 0.5)

#Exercicio 9
fCoelho <- function(n,k) {
  if ( n == 0) {
    return(0)
  }
  if ( n == 1) {
    return(1)
  }
  else {
    return (fCoelho(n-1,k) + k*fCoelho(n-2,k))
  }
}

#Exercicio 10
library(dslabs)
data(murders)

#a
mediaPopulacao <- mean(murders$population)
menorPopulacao <- murders$state[which.min(murders$population)]
maiorPopulacao <- murders$state[which.max(murders$population)]

maiorPopulacao
menorPopulacao
mediaPopulacao

#b
murders$morte <- 10000*murders$total/murders$population
murders$morte

#c
nome <- murders$state[order(murders$total/murders$population)]
nome

#d
murders$taxa <- murders$total/murders$population
murders$taxa

inferior <- murders$state[murders$taxa < 0.05]
inferior

superior <- murders$state[murders$taxa > 0.5]
superior

#e
maiorTaxa <- murders$state[murders$taxa == max(murders$taxa)]
maiorTaxa

menorTaxa <- murders$state[murders$taxa == min(murders$taxa)]
menorTaxa

#f
northcentral <- murders[murders$region == "North Central",]
northcentral

west <- murders[murders$region == "West",]
west

south <- murders[murders$region == "South",]
south

northeast <- murders[murders$region == "Northeast",]
northeast

ncmedia <- mean(northcentral$taxa)
ncmedia

wmedia <- mean(west$taxa)
wmedia

smedia <- mean(south$taxa)
smedia

nemedia <- mean(northeast$taxa)
nemedia

ncdesvio <- sqrt(sum((northcentral$taxa - ncmedia)^2)/length(northcentral))
ncdesvio


nedesvio <- sqrt(sum((northeast$taxa - nemedia)^2)/length(northeast))
nedesvio

wdesvio <- sqrt(sum((west$taxa - wmedia)^2)/length(west))
wdesvio

sdesvio <- sqrt(sum((south$taxa - smedia)^2)/length(south))
sdesvio

murders$state[mean(south$taxa) == max(smedia, wmedia, nemedia, ncmedia)]

min(smedia, wmedia, nemedia, ncmedia)

boxplot(south$taxa, west$taxa, northcentral$taxa, northeast$taxa, names =  c("South", "West", "North Central", "Northeast"))