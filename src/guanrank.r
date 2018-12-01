dyn.load(paste("guanrank_r", .Platform$dynlib.ext, sep=""))
guanrank <- function(infile){
  df <- read.csv(infile)
  n <- nrow(df)

  res <- .C("guanrank", infile, rank=double(n), pid=character(n))

  return (data.frame(res$pid, res$rank))
}
