source("gerar_dados.R")
source("remove_outlier.R")

#1.2.1
dad <- gerar_dados(m1, m2, m3)
dad <- remove_outlier(dad)
masculinoDados <- subset(dad, sub = (Sexo == "M"))
femininoDados <- subset(dad, sub = (Sexo == "F"))

masculinoDados <- remove_outlier(masculinoDados)
femininoDados <- remove_outlier(femininoDados)

(masculinotb <- fdt(masculinoDados$Y1))
(femininotb <- fdt(femininoDados$Y1))

write.csv(masculinotb, "../graphs/masculinotb.csv")
write.csv(femininotb, "../graphs/femininotb.csv")
