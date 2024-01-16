source("gerar_dados.R")
source("questao3.2.1.R")


dados <- gerar_dados_rl(m1, m2, m3)
x11()
png(filename="../graphs/q3.2.2", width=900, height=450)
par(mfrow=c(1, 2))

plot(dados$Y ~ dados$X,
     xlim = c(0,10), 
     ylim = c(0,14), 
     pch = 20, 
     col = "blue",
     main= "A: Polinomio I grau",
     xlab="X",
     ylab="Y")

Beta = round(Rl_grau1$coefficients[1],4)
alfa = round(Rl_grau1$coefficients[2],4)
r = cor(dados$X, dados$Y) * cor(dados$X, dados$Y)

Rl_grau1
r
text(2, 14, expression("Ŷ = 2.5609 + 1.115X") ,cex=1)
text(2, 13.3, expression("r² = 0.8999") ,cex =1)

lines(spline(fitted(Rl_grau1) ~ dados$X,
             n=1e2),
      col='red')
      

plot(dados$Y ~ dados$X,
     xlim = c(0,10), 
     ylim = c(0,14), 
     pch = 20, 
     col = "blue",
     main= "B: Polinomio II grau",
     xlab="X",
     ylab="Y")

Rl_grau2
r
text(2.5, 14, expression("Ŷ = 1.1411 + 2.0734X - 0.0958X²") ,cex =1)
text(2.5, 13.3, expression("r² = 0.9524") ,cex =1)
lines(spline(fitted(Rl_grau2) ~ dados$X,
             n=1e2),
      col='red')

dev.off()
      
#3.2.3
#O melhor modelo ? o polim?nio de grau 2 pois:
#ele tem um r^2 ajustado maior, indicando maior capacidade de previs?o quando 
#novas vari?veis relevantes s?o acrescentadas.
#Ele possui um erro quadratico m?dio menor, indicando maior poder de previs?o nos dados.
#Ele possui menor erro residual padr?o, sugerindo maior adequa??o dos dados.

#3.2.4
#N?o, r^2 n?o ? adequado nem mesmo para medir se um modelo ? adequado para as
#observa??es, pois n?o diz nada sobre sua capacidade de previs?o dos dados.
#principalmente quandoa rela??o entre as vari?veis ? n?o linear.

