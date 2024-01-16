source("gerar_dados.R")

#..Faz o tratamento dos dados para as quest�es 2.2.1, 2.2.2 e 2.2.3
dad <- gerar_tdf(m1, m2, m3)

#Extrai as frequ�ncias do dataframe
frequencias <- c(unlist(dad[2]))

#Converte para objeto da classe fdt
dadFdt <- make.fdt(frequencias, start=10,end=100)

#printa:

dadFdt
