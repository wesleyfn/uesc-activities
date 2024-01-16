m1 <- 201920240
m2 <- 201820212
m3 <- 201920072
library(mvtnorm)
library(Matrix)
library(fdth)

#m1 <- 202210000
#m2 <- 202210000
#m3 <- 202210000

#.. Função: gerar_dados
gerar_dados <- function(m1 = NULL,
                        m2 = NULL,
                        m3 = NULL,
                        n = 2e3)
{
  stopifnot(is.numeric(m1) &
            is.numeric(m2) &
            is.numeric(m3))
  
  set.seed(m1+m2+m3)
  
  m_1 <- runif(1,
               min = 20,
               max = 40)
  
  m_2 <- runif(1,
               min = 20,
               max = 40)
  
  ## Categórica
  n_cat_1 <- n / 10 * sample(4:8,
                             1)
  
  ## Matriz de variâncias e covariâncias
  sigma_1 <- matrix(c(m_1,
                      m_1 / 1.1,
                      m_1 / 1.1,
                      m_2),
                    ncol = 2)
  
  sigma_2 <- matrix(c(m_1,
                      -1 * (m_2 / 1.2),
                      -1 * (m_2 / 1.2),
                      m_2),
                    ncol = 2)
  
  require(Matrix) # S4
  near_1 <- nearPD(sigma_1)
  
  near_2 <- nearPD(sigma_2)
  
  sigma_1 <- matrix(near_1[['mat']]@x,
                    nc = ncol(sigma_1))
  
  sigma_2 <- matrix(near_2[['mat']]@x,
                    nc = ncol(sigma_2))
  
  ## Escala proporcional
  require(mvtnorm)
  v_pro_1 <- round(rmvnorm(
    n = n_cat_1,
    mean = c(m_1,
             m_2),
    sigma = sigma_1
  ),
  2)
  
  v_pro_2 <- round(rmvnorm(
    n = (n - n_cat_1),
    mean = c(m_1,
             m_2),
    sigma = sigma_2
  ),
  2)
  
  ## Escala categórica
  cat_1 <- rep('M',
               n_cat_1)
  
  cat_2 <- rep('F',
               n - n_cat_1)
  
  v_pro <- c('v_pro_1',
             'v_pro_2')
  
  v_cat <- c('cat_1',
             'cat_2')
  
  ord <- sample(1:2,
                2)
  
  sexo <- c(eval(parse(text = v_cat[ord[1]])),
            eval(parse(text = v_cat[ord[2]])))
  
  
  ## Frame de dados
  res <- as.data.frame(rbind(eval(parse(text = v_pro[ord[1]])),
                             eval(parse(text = v_pro[ord[2]]))))
  
  res <- cbind(res,
               sexo)
  
  colnames(res) <- c('Y1',
                     'Y2',
                     'Sexo')
  
  ## Outlier v_pro_1
  n_out_v1 <- sample(10:20,
                     1)
  
  out_v1 <- sample(1:length(res[, 1]),
                   n_out_v1)
  
  res[, 1][out_v1] <- sample(730:999,
                             n_out_v1)
  
  ## Outlier v_pro_2
  n_out_v2 <- sample(10:30,
                     1)
  
  out_v2 <- sample(1:length(res[, 2]),
                   n_out_v2)
  
  res[, 2][out_v2] <- sample(200:300,
                             n_out_v2)
  
  ## NAs
  res[, 1][sample(1:n,
                  sample(10:20,
                         1))] <- NA
  
  res[, 2][sample(1:n,
                  sample(10:20,
                         1))] <- NA
  
  res[, 3][sample(1:n,
                  sample(10:20,
                         1))] <- NA
  
  ## Negativos
  res[, 1][sample(1:n,
                  sample(10:20,
                         1))] <- -999
  
  res[, 2][sample(1:n,
                  sample(10:20,
                         1))] <- -999
  
  invisible(res)
}
#.. Exemplo de uso: gerar_dados
# dad <- gerar_dados(m1=202210000,
#                    m2=202210000,
#                    m3=202210000)
# str(dad)

#.. Função: gerar_dados_rl
gerar_dados_rl <- function(m1 = NULL,
                           m2 = NULL,
                           m3 = NULL,
                           n = 10)
{
  stopifnot(is.numeric(m1) &
              is.numeric(m2) &
              is.numeric(m3))
  
  set.seed(sum(m1,
               m2,
               m3))
  
  X <- seq(0, 10, length = n)
  Y <- 1 + 2 * X+-.08 * X ^ 2 + rnorm(n)
  
  res <- data.frame(X,
                    Y)
  
  invisible(res)
}
#.. Exemplo de uso: gerar_dados_rl
# dad_rl <- gerar_dados_rl(m1=202210000,
#                          m2=202210000,
#                          m3=202210000)
# str(dad_rl)
# plot(dad_rl,
#      pch=20)


#.. Função: gerar_tdf
gerar_tdf <- function(m1 = NULL,
                      m2 = NULL,
                      m3 = NULL)
{
  stopifnot(is.numeric(m1) &
              is.numeric(m2) &
              is.numeric(m3))
  
  set.seed(sum(m1,
               m2,
               m3))
  
  classes <- c(
    "[10, 020)",
    "[20, 030)",
    "[30, 040)",
    "[40, 050)",
    "[50, 060)",
    "[60, 070)",
    "[70, 080)",
    "[80, 090)",
    "[90, 100)"
  )
  
  X <- c(seq(f = 10,
             t = 50,
             b = 10),
         seq(f = 40,
             t = 10,
             b = -10))
  
  Y <- sample(1:3,
              length(X),
              rep = T)
  
  f <- (X - Y)
  
  
  rfp <- round(100 * f / sum(f),
               2)
  
  cfp <- round(100 * cumsum(f / sum(f)),
               2)
  
  res <- data.frame(classes,
                    f,
                    rfp,
                    cfp)
  
  names(res) <- c('Classes',
                  'f',
                  'rf(%)',
                  'cf(%)')
  
  invisible(res)
}
#.. Exemplo de uso:  gerar_tdf
#tb <- gerar_tdf(m1=202210000,
#                m2=202210000,
#                m3=202210000)

#str(tb)
#tb
