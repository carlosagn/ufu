#ALUNOS:
#Carlos Augusto Gomes Neto 11821BCC016 
#Victor Borges Zuccolotto 11811BCC034 
#Vinnicius Pereira da Silva 11821BCC046
#Pedro Henrique da Silva Oliveira 11811BCC040 
#Vitor Santini Bessa 11821BCC010

#ex1
pinguins = read.csv("C:\\Users\\netoc\\Desktop\\Estudos\\Graduação\\R\\5-lista-ex\\penguins_size.csv", header = TRUE, sep =',')
pinguins$species = as.factor(pinguins$species)
pinguins$sex = as.factor(pinguins$sex)
str(pinguins)

#a
pesoMedio <- mean(pinguins$body_mass_g, na.rm = TRUE)
comprimentoMedio <- mean(pinguins$flipper_length_mm, na.rm = TRUE)

dpPeso <- sd(pinguins$body_mass_g, na.rm = TRUE)
dpComprimento <- sd(pinguins$flipper_length_mm, na.rm = TRUE)


#b
adeliePinguins <- pinguins[pinguins$species == 'Adelie', ]

peso_medio_adelie <- mean(adeliePinguins$body_mass_g, na.rm = TRUE)

peso_sd_adelie <- sd(adeliePinguins$body_mass_g, na.rm = TRUE)

comprimento_medio_adelie <- mean(adeliePinguins$flipper_length_mm, na.rm = TRUE)

comprimento_sd_adelie <- sd(adeliePinguins$flipper_length_mm, na.rm = TRUE)

chinsPinguins <- pinguins[pinguins$species == 'Chinstrap', ]

peso_medio_chins <- mean(chinsPinguins$body_mass_g, na.rm = TRUE)

peso_sd_chins <- sd(chinsPinguins$body_mass_g, na.rm = TRUE)

comprimento_medio_chins <- mean(chinsPinguins$flipper_length_mm, na.rm = TRUE)

comprimento_sd_chins <- sd(chinsPinguins$flipper_length_mm, na.rm = TRUE)

gentooPinguins <- pinguins[pinguins$species == 'Gentoo', ]


peso_medio_gentoo <- mean(gentooPinguins$body_mass_g, na.rm = TRUE)

peso_sd_gentoo <- sd(gentooPinguins$body_mass_g, na.rm = TRUE)

comprimento_medio_gentoo <- mean(gentooPinguins$flipper_length_mm, na.rm = TRUE)

comprimento_sd_gentoo <- sd(gentooPinguins$flipper_length_mm, na.rm = TRUE)

male <- pinguins[pinguins$sex == 'MALE', ]

pesoMedioMale <- mean(male$body_mass_g, na.rm = TRUE)

dpPesoMale <- sd(male$body_mass_g, na.rm = TRUE)

comprimentoMedioMale <- mean(male$flipper_length_mm, na.rm = TRUE)

dpComprimentoMale <- sd(male$flipper_length_mm, na.rm = TRUE)


female <- pinguins[pinguins$sex == 'FEMALE', ]
pesoMedioFemale <- mean(female$body_mass_g, na.rm = TRUE)



DpPesoFemale <- sd(female$body_mass_g, na.rm = TRUE)

comprimentoMedioFemale <- mean(female$flipper_length_mm, na.rm = TRUE)


DpComprimentoFemale <- sd(female$flipper_length_mm, na.rm = TRUE)

#d
plot(pinguins$flipper_length_mm, pinguins$body_mass_g) #plotou um grafico contra o outro

#e
cor(pinguins$flipper_length_mm, pinguins$body_mass_g, use="complete.obs")

#f
#As asas do pinguim tem relacao forte com a massa dos mesmos

#g
wingWhLm <- lm(body_mass_g ~ flipper_length_mm, data = pinguins)
wingWhLm

#h
#Representa a variaçao do peso do pinguim quando ocorre 1mm de aumento da asa do mesmo

#i
weightPinguin <- function (lengthWing) {
  return(49.69 * lengthWing - 5780.83)
}
weightPinguin(204)


