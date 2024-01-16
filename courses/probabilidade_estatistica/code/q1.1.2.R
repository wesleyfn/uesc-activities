source("gerar_dados.R")
source("remove_outlier.R")

#1.1.2
png(filename="../graphs/q1.1.2", width=900, height=450)

  dad <- gerar_dados(m1, m2, m3)
  dad <- remove_outlier(dad)
  masculinoDados <- subset(dad, sub = (Sexo == "M"))
  femininoDados <- subset(dad, sub = (Sexo == "F"))
  masculinoDados <- remove_outlier(masculinoDados)
  femininoDados <- remove_outlier(femininoDados)
  
  par(mfrow=c(1, 2))
  boxplot(masculinoDados$Y1, 
          masculinoDados$Y2, 
          main='Masculino', 
          names=c('Y1', 'Y2'))
  
  boxplot(femininoDados$Y1, 
          femininoDados$Y2, 
          main='Feminino', 
          names=c('Y1', 'Y2'))

dev.off()
