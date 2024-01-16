source("q2.2.R")

#Medidas de tend?ncia central da tabela de distribui??o de frequ?ncia
mediaFdt <- round(mean(dadFdt),2)
medianaFdt <- round(median(dadFdt),2)
modaFdt <- round(mfv(dadFdt),2)

#Cria a matriz com os valores
tendenciaCentralFdt <- matrix(c(mediaFdt, medianaFdt, modaFdt),ncol=3)

colnames(tendenciaCentralFdt) <- c("m","md","mo")
rownames(tendenciaCentralFdt) <- "medida"

as.data.frame(tendenciaCentralFdt)
