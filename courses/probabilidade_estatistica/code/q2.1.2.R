source("q2.1.R")

#Quartis:
quartilMasculinoY1 = round(quantile(Y1Masculino, p=c(0.25, 0.5, 0.75)), 2)
quartilMasculinoY2 = round(quantile(Y2Masculino, p=c(0.25, 0.5, 0.75)), 2)

quartilFemininoY1 = round(quantile(Y1Feminino, p=c(0.25, 0.5, 0.75)), 2)
quartilFemininoY2 = round(quantile(Y2Feminino, p=c(0.25, 0.5, 0.75)), 2)

#Matriz para quartil masculino:
matrizQuartilMasculino <- matrix(c(quartilMasculinoY1,
                                   quartilMasculinoY2), 
                                 ncol = 3, 
                                 byrow=TRUE)

colnames(matrizQuartilMasculino) <- c("25%","50%","75%")
rownames(matrizQuartilMasculino) <- c("Y1","Y2")

#Matriz para quartil feminino
matrizQuartilFeminino <- matrix(c(quartilFemininoY1,
                                  quartilFemininoY2), 
                                ncol = 3, 
                                byrow=TRUE)

colnames(matrizQuartilFeminino) <- c("25%","50%","75%")
rownames(matrizQuartilFeminino) <- c("Y1","Y2")

#Decis
decilMasculinoY1 = round(quantile(Y1Masculino, p=seq(0.1, 0.9, 0.1)), 2)
decilMasculinoY2 = round(quantile(Y2Masculino, p=seq(0.1, 0.9, 0.1)), 2)

decilFemininoY1 = round(quantile(Y1Feminino, p=seq(0.1, 0.9, 0.1)), 2)
decilFemininoY2 = round(quantile(Y2Feminino, p=seq(0.1, 0.9, 0.1)), 2)
#Matrizes:
matrizDercilMasculino <-matrix(c(decilMasculinoY1,
                                 decilMasculinoY2), 
                               ncol = 9, 
                               byrow=TRUE)

matrizDercilFeminino <- matrix(c(decilFemininoY1,
                                 decilFemininoY2),
                               ncol = 9, 
                               byrow=TRUE)

colnames(matrizDercilMasculino) <- c("10%","20%","30%","40%","50%","60%","70%","80%","90%")
rownames(matrizDercilMasculino) <- c("Y1","Y2")

colnames(matrizDercilFeminino) <- c("10%","20%","30%","40%","50%","60%","70%","80%","90%")
rownames(matrizDercilFeminino) <- c("Y1","Y2")


#..Respostas
matrizQuartilMasculino
matrizQuartilFeminino

matrizDercilMasculino
matrizDercilFeminino


