source("q2.1.R")

#Calcula a média dos valores.
mediaMasculinoY1 <- round(mean(Y1Masculino), 2)
mediaMasculinoY2 <- round(mean(Y2Masculino), 2)

mediaFemininoY1 <- round(mean(Y1Feminino), 2)
mediaFemininoY2 <- round(mean(Y2Feminino), 2)

#Calcula a mediana dos valores.
medianMasculinoY1 <- round(median(Y1Masculino), 2)
medianMasculinoY2 <- round(median(Y2Masculino), 2)

medianFemininoY1 <- round(median(Y1Feminino), 2)
medianFemininoY2 <- round(median(Y2Feminino), 2)

#Calcula a moda dos valores.
modeMasculinoY1 <- round(mfv(Y1Masculino), 2)
modeMasculinoY2 <- round(mfv(Y2Masculino), 2)

modeFemininoY1 <- round(mfv(Y1Feminino), 2)
modeFemininoY2 <- round(mfv(Y2Feminino), 2)

#Numero
qtdMasculinoY1 <- length(Y1Masculino)
qtdFemininoY1 <- length(Y1Feminino)

qtdMasculinoY2 <- length(Y2Masculino)
qtdFemininoY2 <- length(Y2Feminino)

#Constroi uma matriz e nomea as colunas com os nomes das mediddas de tendência central,
#e as linhas com os nomes das variáveis.
matrizMasculino <- matrix(c(qtdMasculinoY1, 
                           mediaMasculinoY1,
                           medianMasculinoY1,
                           modeMasculinoY1,
                           qtdMasculinoY2,
                           mediaMasculinoY2, 
                           medianMasculinoY2,
                           modeMasculinoY2),
                         ncol=4,
                         byrow=TRUE)

colnames(matrizMasculino) <- c("n","m","md","mo")
rownames(matrizMasculino) <- c("Y1","Y2")

#matriz para o sexo feminino

matrizFeminino <- matrix(c(qtdFemininoY1, 
                          mediaFemininoY1,
                          medianFemininoY1,
                          modeFemininoY1,
                          qtdFemininoY2,
                          mediaFemininoY2, 
                          medianFemininoY2,
                          modeFemininoY2),
                        ncol=4,
                        byrow=TRUE)

colnames(matrizFeminino) <- c("n", "m","md","mo")
rownames(matrizFeminino) <- c("Y1","Y2")

#..Respostas

#Tabelas masculino e feminino de tendência central
as.data.frame(matrizMasculino)
as.data.frame(matrizFeminino)
