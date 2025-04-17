fun main() {
    val str = readln()

    for(i in 0 until  str.length / 2) {
        if(str[i] != str[str.length - i - 1]) {
            println(0)
            return
        }
    }
    println(1)
}