dyn.load(paste("guanrank_r", .Platform$dynlib.ext, sep=""))
guanrank <- function(infile){
  df <- read.csv(infile)
  n <- nrow(df)

  pid <- .C("guanrank", infile, rank=double(n), pid=character(n))$pid
  rank <- .C("guanrank", infile, rank=double(n), pid=character(n))$rank

  return (pid)
}
