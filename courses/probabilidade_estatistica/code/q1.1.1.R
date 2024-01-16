source("gerar_dados.R")
source("remove_outlier.R")

#1.1.1
png(filename="../graphs/q1.1.1", width=900, height=450)

  dad <- gerar_dados(m1, m2, m3)
  par(mfrow=c(1, 2))
  boxplot(dad$Y1, 
          dad$Y2, 
          main='Antes', 
          names=c('Y1', 'Y2'))
  
  #Remove outliers
  dad <- remove_outlier(dad)
  boxplot(dad$Y1, 
          dad$Y2, 
          main='Após', 
          names=c('Y1', 'Y2'))

dev.off()

