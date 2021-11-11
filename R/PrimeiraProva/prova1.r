#Carlos Augusto Gomes Neto

#variavel global para monte carlo
x <- 10000

#Ex 1
library(dslabs)
data(heights)

heights <- read.csv("heights.csv", header = TRUE)

alturas <- c()

#a
for (i in 1:1050) {
  heights["alt.cm"] <- heights$height * 2.54
}

#b
mean(heights$sex == "Male")

#c
max(heights$alt.cm)

indice <- which.max(heights$alt.cm)
indice

sexoMax <- heights$sex[indice]
sexoMax

#d
min(heights$alt.cm)

indice2 <- which.min(heights$alt.cm)
indice2

sexoMin <- heights$sex[indice2]
sexoMin

#e
mean(heights$alt.cm)
sd(heights$alt.cm)

#f
alturaH <- data.frame(alturaH$sexo == "sexo",alturaH$alt.cm == "alt.cm")
alturaF <- data.frame(alturaF$sexo == "sexo",alturaF$alt.cm == "alt.cm")

alturaH <- alturaH$sexo[heights$sex == "Male"]
alturaF <- alturaF$sexo[heights$sex == "Female"]

alturaH <- alturaH$alt.cm[heights$sex == "Male"]
alturaF <- alturaF$alt.cm[heights$sex == "Female"]


#Ex 2
#1 = cara
#2 = coroa
vovo <- 18 #dinheiro vovo
jorel <- 7 #dinheiro jorel
vitoriaVovo <- c() #guarda quantas vezes vovo ganhou
vitoriaJorel <- c() #guarda quantas vezes jorel ganhou

for ( i in 1:x) { #feito 10000 vezes MC
  repeat {
    moeda <- sample(1:2, 1, replace = TRUE)
    if ( moeda == 1) {
      jorel <- jorel - 1
      vovo <- vovo + 1
      if ( jorel == 0 ) {
        vitoriaVovo <- c(vitoriaVovo,1)
        break
      }
    }
    if (moeda == 2) {
      jorel <- jorel + 1
      vovo <- vovo - 1
      if ( vovo == 0 ) {
        vitoriaJorel <- c(vitoriaJorel,1)
        break
      }
    }
  }  
}

media <- length(vitoriaJorel)/x
media

#Ex 3
#a
vetor <- gerador(5000)
vetor


gerador <- function(n) {
  runif(n,0,1)
}
