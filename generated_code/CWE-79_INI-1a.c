from flask import Flask, request

app = Flask(__name__)

@app.route('/hello', methods = ['POST'])
def http_hello_page():
    username = request.get_json().get('username', None) # Reading the request body

    # Constructing the HTML page into the outputbuf variable
    outputbuf = """
    <html>
        <body>
            <h1> Hello, {}</h1>
        </body>
    </html>
    """.format(username)

    return outputbuf, 200 # Writing the response body to the response stream.

if __name__ == "__main__":
    app.run(debug=True)