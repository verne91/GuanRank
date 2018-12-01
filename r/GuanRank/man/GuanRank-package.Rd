\name{GuanRank-package}
\alias{GuanRank-package}
\alias{GuanRank}
\docType{package}
\title{
\packageTitle{GuanRank}
}
\description{
\packageDescription{GuanRank}
}
\details{

The DESCRIPTION file:
\packageDESCRIPTION{GuanRank}
\packageIndices{GuanRank}
This package provides a fast C++ version of GuanRank 
}
\author{
\packageAuthor{GuanRank}

Maintainer: \packageMaintainer{GuanRank}
}
\references{
http://guanlab.ccmb.med.umich.edu/yuanfang/Guan_rank.pdf
}

~~ Optionally other standard keywords, one per line, from file KEYWORDS in ~~
~~ the R documentation directory ~~

\keyword{ package }
\seealso{
~~ Optional links to other man pages, e.g. ~~
~~ \code{\link[<pkg>:<pkg>-package]{<pkg>}} ~~
}
\examples{
Input: CSV file with three columns (Patient ID, Time, Status).

Example data can be found at: https://github.com/verne91/GuanRank/blob/master/data/sim_data.csv

The first 10 rows of example input "sim_data.csv":
"patient_ID","time","status"
1,376,1
2,331,0
3,597,1
4,150,1
5,521,1
6,535,1
7,831,0
8,433,1
9,591,0

guanrank("/sim_data.csv")

The first 10 rows of the data frame returned:
 
	PatientID  Score
1           1 0.823626008
2           2 0.269745918
3           3 0.594761949
4           4 0.964421294
5           5 0.656664633
6           6 0.642736111
7           7 0.041349843
8           8 0.744684709
9           9 0.144459342

}
