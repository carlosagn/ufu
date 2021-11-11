#Ex 1 -> basicamente tem os metodos, dps monta o cluster dendograma e divide em aglomerados atraves de K
#a
mat = rbind(c(0,9,3,6,11), c(9,0,7,5,10), c(3,7,0,9,2), c(6,5,9,0,8), c(11,10,2,8,0))
mat = as.dist(mat)

cluster = hclust(mat,method = "complete")
plot (cluster)

#b 
mat = rbind(c(0,9,3,6,11), c(9,0,7,5,10), c(3,7,0,9,2), c(6,5,9,0,8), c(11,10,2,8,0))
mat = as.dist(mat)
cluster = hclust(mat,method = "single")
plot (cluster)

#c
mat = rbind(c(0,9,3,6,11), c(9,0,7,5,10), c(3,7,0,9,2), c(6,5,9,0,8), c(11,10,2,8,0))
mat = as.dist(mat)

cluster = hclust(mat,method = "complete")
plot (cluster)
rect.hclust(cluster, k = 2) #k = 2 pq eh dois aglomerados

#d
mat = rbind(c(0,9,3,6,11), c(9,0,7,5,10), c(3,7,0,9,2), c(6,5,9,0,8), c(11,10,2,8,0))
mat = as.dist(mat)
cluster = hclust(mat,method = "single")
plot (cluster)
rect.hclust(cluster, k = 2) #k = 2 pq eh dois aglomerados

#Ex 2
library(rpart)
library(rpart.plot)
library(tree)

### Leitura do conjunto de dados
patients = read.csv("C:\\Users\\netoc\\Desktop\\Estudos\\Graduação\\R\\4-lista-ex\\heart.txt", header = TRUE, sep = ",");

### Remoção de variáveis inúteis
patients = patients[, -1]

patients$heart_attack = as.factor(patients$heart_attack)
patients$exercises = as.factor(patients$exercises)
patients$smokes = as.factor(patients$smokes)
patients$sex = as.factor(patients$sex)
patients$chest_pain = as.factor(patients$chest_pain)

str(patients)

### Embaralhando
patients = patients[sample(nrow(patients)), ]
train = patients[1:4, ]
test = patients[5:6, ] 
### Separação das variáveis
sick = patients[patients$heart_attack == "yes", ]
nonSick = patients[patients$heart_attack == "no", ]
summary(sick)
summary(nonSick)

modelHeart <- rpart(heart_attack ~., data = train, parms = list(split = "gini"))

rpart.plot(modelHeart, extra = 101)

codigo <- rpart(heart_attack ~., data = train, parms = list(split = "gini"))

#Ex 3
kids = read.csv("C:\\Users\\netoc\\Desktop\\Estudos\\Graduação\\R\\4-lista-ex\\SBI.csv")
kids
str(kids)

#a
kidsValues = kids$sbi == "NotApplicable"
for(i in 1:length(kidsValues)) {
  if(kidsValues[i]) {
    kidsValues[i] = "no" 
  } else {
    kidsValues[i] = "yes"
  }
}
kids$infection = as.factor(kidsValues)

#b
kids = kids[, c(-1, -2, -8)]
kids

#c
reordered = kids[sample(nrow(kids)), ]
nrow(kids)*0.8
train = reordered[1:1878, ]
test = reordered[1879:nrow(kids), ]
train

#d
library(tree)
library(rpart)
library(rpart.plot)

modelHeart = rpart(infection ~., data = train, parms = list(split = "gini"))
rpart.plot(modelHeart, extra = 101)

predictHeart = predict(modelHeart, newdata = test, type = "class")
mean(predictHeart == test$infection)
table(test$infection, predictHeart)

#e
library(randomForest)
rf.modelHeart = randomForest(infection~., data = train)
rf.modelHeart
rf.predictHeart = predict(rf.modelHeart, newdata = test)

mean(test$infection == rf.predictHeart)
table(test$infection, rf.predictHeart)













