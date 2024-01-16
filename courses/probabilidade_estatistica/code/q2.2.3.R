source("q2.2.R")
at_t <- function(x)
{
  # Verifica��o da classe de x: seguran�a apenas!
  if (!inherits(x,
                'fdt'))
    stop("O argumento x n�o � da classe 'fdt'.\n\n")
  
  pm_max <- x$breaks[['end']] -
    (x$breaks[['h']] / 2)
  
  pm_min <- x$breaks[['start']] +
    (x$breaks[['h']] / 2)
  
  pm_max - pm_min
}

#medidas de dispers?o
amplitudeTotal <- at_t(dadFdt)
varianciaFdt <- var(dadFdt)
desvioPadraoFdt <- sd(dadFdt)
covarianciaFdt <- desvioPadraoFdt/mean(dadFdt)


matrizDispersao <- round(matrix(c(amplitudeTotal, 
                                  varianciaFdt, 
                                  desvioPadraoFdt, 
                                  covarianciaFdt),
                                ncol=4), 2)

colnames(matrizDispersao) <- c("a.t","variância","d.padrão","c.v")
rownames(matrizDispersao) <- "medida"

as.data.frame(matrizDispersao)

