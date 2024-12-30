from flask import Flask, render_template, request
from cpf import validar_cpf, criar_cpf

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        cpf_input = request.form.get("cpf")
        if cpf_input:
            if validar_cpf(cpf_input):
                return render_template("result.html", cpf=cpf_input, valid=True)
            else:
                return render_template("result.html", cpf=cpf_input, valid=False)
    return render_template("index.html")

@app.route("/generate", methods=["GET"])
def generate():
    cpf_gerado = criar_cpf()
    return render_template("result.html", cpf=cpf_gerado, valid=True)

if __name__ == "__main__":
    app.run(debug=True)
