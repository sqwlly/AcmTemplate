/*************************************************************************
    > File Name: fasterRead.java
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月17日 星期一 21时20分28秒
	> 加快java的读入
 ************************************************************************/
static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
