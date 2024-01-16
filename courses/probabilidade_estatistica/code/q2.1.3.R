source("q2.1.R")
#Medidas de dispers?o

mediaMasculinoY1 <- mean(Y1Masculino)
mediaMasculinoY2 <- mean(Y2Masculino)

mediaFemininoY1 <- mean(Y1Feminino)
mediaFemininoY2 <- mean(Y2Feminino)

amplitudeTotalMasculinoY1 = max(Y1Masculino) - min(Y1Masculino)
amplitudeTotalMasculinoY2 = max(Y2Masculino) - min(Y2Masculino)

amplitudeTotalFemininoY1 = max(Y1Feminino) - min(Y1Feminino)
amplitudeTotalFemininoY2 = max(Y2Feminino) - min(Y2Feminino)


varianciaMasculinoY1 = round(var(Y1Masculino),2)
varianciaMasculinoY2 = round(var(Y2Masculino),2)

desvioPadraoMasculinoY1 = round(sd(Y1Masculino),2)
desvioPadraoMasculinoY2 = round(sd(Y2Masculino),2)

coeficienteVariacaoMasculinoY1 = round((desvioPadraoMasculinoY1/mediaMasculinoY1) * 100,2)
coeficienteVariacaoMasculinoY2 = round((desvioPadraoMasculinoY2/mediaMasculinoY2) * 100,2)

varianciaFemininoY1 = round(var(Y1Feminino),2)
varianciaFemininoY2 = round(var(Y2Feminino),2)

desvioPadraoFemininoY1 = round(sd(Y1Feminino),2)
desvioPadraoFemininoY2 = round(sd(Y2Feminino),2)

coeficienteVariacaoFemininoY1 = round((desvioPadraoFemininoY1/mediaFemininoY1) * 100,2)
coeficienteVariacaoFemininoY2 = round((desvioPadraoFemininoY2/mediaFemininoY2) * 100,2)

#matrizes

matrizDispersaoMasculino <- matrix(c(amplitudeTotalMasculinoY1,
varianciaMasculinoY1, desvioPadraoMasculinoY1,coeficienteVariacaoMasculinoY1, amplitudeTotalMasculinoY2, varianciaMasculinoY2, desvioPadraoMasculinoY2, 
coeficienteVariacaoMasculinoY2),
ncol=4, byrow = TRUE)

colnames(matrizDispersaoMasculino) <- c("a.t","vari?ncia","d.padr?o","c.v")
rownames(matrizDispersaoMasculino) <- c("Y1","Y2")

matrizDispersaoFeminino <- matrix(c(amplitudeTotalFemininoY1,
varianciaFemininoY1, desvioPadraoFemininoY1,coeficienteVariacaoFemininoY1,
amplitudeTotalFemininoY2, varianciaFemininoY2, desvioPadraoFemininoY2, coeficienteVariacaoFemininoY2),ncol=4, byrow = TRUE)

colnames(matrizDispersaoFeminino) <- c("a.t","vari?ncia","d.padr?o","c.v")
rownames(matrizDispersaoFeminino) <- c("Y1","Y2")

#Tabelas masculino e feminino de dispers?o
as.data.frame(matrizDispersaoMasculino)
as.data.frame(matrizDispersaoFeminino)

