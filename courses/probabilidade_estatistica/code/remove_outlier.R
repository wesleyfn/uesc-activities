remove_outlier <- function(x, type=2)
{
  ## Remover NAs
  x <- na.omit(x)
  
  while(1) 
  {
    ## Quartis
    q.t <- quantile(x$Y1,
                    type=type)[2:4]
    
    q.r <- quantile(x$Y2,
                    type=type)[2:4]
    
    ## Distâncias interquartílicas - iqr
    iqr.t <- q.t[3] - q.t[1]
    iqr.r <- q.r[3] - q.r[1]
    
    ## Identificação de outliers
    out <- subset(x,
                  Y1 >= q.t[3] + 1.5 * iqr.t |
                    Y1 <= q.t[1] - 1.5 * iqr.t |
                    Y1 < 0
                  |
                    Y2 >= q.r[3] + 1.5 * iqr.r |
                    Y2 <= q.r[1] - 1.5 * iqr.r |
                    Y2 < 0)
    
    ## Condição de saída
    if (dim(out)[1] == 0)
      return(x)
    
    ## Remoção de outliers
    x <- subset(x,
                Y1 < q.t[3] + 1.5 * iqr.t &
                  Y1 > q.t[1] - 1.5 * iqr.t &
                  Y1 >= 0
                &
                  Y2 < q.r[3] + 1.5 * iqr.r &
                  Y2 > q.r[1] - 1.5 * iqr.r &
                  Y2 >= 0)
  }
}