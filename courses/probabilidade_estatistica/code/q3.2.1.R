source("gerar_dados.R")
dados <- gerar_dados_rl(m1, m2, m3)


#Xdado <- cbind(1, dados$X)
#Ydado <- cbind(1,dados$Y)

#XlXdado <- t(Xdado) %*% Xdado
#XlXdado_inv <- solve(XlXdado)


#YlYdado <- t(Ydado) %*% Ydado
#YlYdado_inv <- solve(YlYdado)


#XlYdado <- t(Xdado)  %*% Ydado

#b_estimativa <- XlXdado_inv %*% XlYdado
#Y_estimativa <- Xdado %*% b_estimativa
#erros <- Ydado - Y_estimativa

Rl_grau1 <- lm(dados$Y ~ dados$X)
Rl_grau2 <- lm(dados$Y ~ dados$X + I(dados$X^2))

summary(Rl_grau1)

summary(Rl_grau2)
