source("gerar_dados.R")
source("remove_outlier.R")

#..Faz o tratamento dos dados para as quest?es do 2.1
dad <- gerar_dados(m1, m2, m3)
dad <- remove_outlier(dad)
masculinoDados <- subset(dad, sub = (Sexo == "M"))
femininoDados <- subset(dad, sub = (Sexo == "F"))

masculinoDados <- remove_outlier(masculinoDados)
femininoDados <- remove_outlier(femininoDados)

#Seleciona os valores das vari?veis de acordo com  sexo
Y1Masculino <- masculinoDados$Y1
Y1Feminino <- femininoDados$Y1

Y2Masculino <- masculinoDados$Y2
Y2Feminino <- femininoDados$Y2                                          
