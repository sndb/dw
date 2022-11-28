BEGIN {
	print "static const char *words[] = {"
}

{
	printf "\t\"%s\",\n", $2
}

END {
	print "};"
}
