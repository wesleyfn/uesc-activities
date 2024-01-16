source("q2.1.R")

varMasculinoY1 <- round(var(Y1Masculino), 2)
varMasculinoY2 <- round(var(Y2Masculino), 2)
covMasculinoY1Y2 <- round(cov(Y1Masculino, Y2Masculino), 2)

varFemininoY1 <- round(var(Y1Feminino), 2)
varFemininoY2 <- round(var(Y2Feminino), 2)
covFemininoY1Y2 <- round(cov(Y1Feminino, Y2Feminino), 2)

corMasculinoY1Y1 <- round(cor(Y1Masculino, Y1Masculino), 2)
corMasculinoY1Y2 <- round(cor(Y1Masculino, Y2Masculino), 2)

corFemininoY1Y1 <- round(cor(Y1Feminino, Y1Feminino), 2)
corFemininoY1Y2 <- round(cor(Y1Feminino, Y2Feminino), 2)

#Variância e covariância
matrizMasculino1 <- matrix(c(varMasculinoY1,
                            covMasculinoY1Y2,
                            covMasculinoY1Y2,
                            varMasculinoY2),
                          ncol=2,
                          byrow=TRUE)

colnames(matrizMasculino1) <- c("Y1","Y2")
rownames(matrizMasculino1) <- c("Y1","Y2")


matrizFeminino1 <- matrix(c(varFemininoY1,
                            covFemininoY1Y2,
                            covFemininoY1Y2,
                            varFemininoY2),
                          ncol=2,
                          byrow=TRUE)

colnames(matrizFeminino1) <- c("Y1","Y2")
rownames(matrizFeminino1) <- c("Y1","Y2")

#Correlação
matrizMasculino2 <- matrix(c(corMasculinoY1Y1,
                             corMasculinoY1Y2,
                             corMasculinoY1Y2,
                             corMasculinoY1Y1),
                           ncol=2,
                           byrow=TRUE)

colnames(matrizMasculino2) <- c("Y1","Y2")
rownames(matrizMasculino2) <- c("Y1","Y2")


matrizFeminino2 <- matrix(c(corFemininoY1Y1,
                            corFemininoY1Y2,
                            corFemininoY1Y2,
                            corFemininoY1Y1),
                          ncol=2,
                          byrow=TRUE)

colnames(matrizFeminino2) <- c("Y1","Y2")
rownames(matrizFeminino2) <- c("Y1","Y2")

as.data.frame(matrizMasculino1)
as.data.frame(matrizFeminino1)
as.data.frame(matrizMasculino2)
as.data.frame(matrizFeminino2)




