source("q2.2.R")

#Medidas de posi??o quartis e decis

#a vari?vel i refere-se a posi??o de quantis 1 = 10%, 2 = 20%...
quartilFdt <- quantile(dadFdt, i=c(1, 2, 3))

quartilMatriz <- round(matrix(quartilFdt,ncol = 3),2)
colnames(quartilMatriz) <- c("10%","20%","30%")
rownames(quartilMatriz) <- "quartil"

#decis

decilFdt <- numeric()
for(n in 1:9)
{
  decilFdt[n] <- quantile(dadFdt, i=n, probs=seq(0, 1, 0.1))
}

decilMatriz <- round(matrix(decilFdt, ncol=9), 2)

colnames(decilMatriz) <- c("10%","20%","30%","40%","50%","60%","70%","80%","90%")
rownames(decilMatriz) <- "decil"

#tabelas

as.data.frame(quartilMatriz)
as.data.frame(decilMatriz)

