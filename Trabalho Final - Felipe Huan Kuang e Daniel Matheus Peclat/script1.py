#===============================================================================
#
#  TRABALHO - EEL670 - LINGUAGENS DE PROGRAMACAO
#  PROFESSOR: MIGUEL CAMPISTA
#  ALUNOS: DANIEL MATHEUS PECLAT
#          FELIPE HUAN KUANG
#
#===============================================================================


# ==============================
# ==== Importar bibliotecas ====
# ==============================

import pandas as pd

from sklearn                           import svm
from sklearn.naive_bayes               import GaussianNB, MultinomialNB
from sklearn.feature_extraction.text   import CountVectorizer
from sklearn.model_selection           import train_test_split



def celularClassificador (celularCodigo):


   celularCodigo = celularCodigo.lower()
   celularCodigo = [celularCodigo]
    

# ==========================================================
# ==== Ler o arquivo CSV com os dados do conjunto ====
# ==========================================================
    
   dados = pd.read_csv('baseDeDados.csv')
   x = dados['v2'].astype('str')
   y = dados['v1']



# =================================================================
# ==== Separar X e Y em conjunto de treino e conjunto de teste ====
# =================================================================

   x_treino, x_teste, y_treino, y_teste = train_test_split(
      x,
      y,
      test_size=0.25
   )
  

   vectorizer = CountVectorizer()
   features = vectorizer.fit_transform(x_treino)


# =================================================================
# ==== Treinar o modelo ===========================================
# =================================================================

   modelo = svm.SVC()
   modelo.fit(features, y_treino)

   vector_test = vectorizer.transform(x_teste)
    
    
# ==================================================================
# ==== Obter as respostas do classificador no conjunto =============
# ==================================================================

   vector = vectorizer.transform(celularCodigo)
   resultado = modelo.predict(vector)
	
   print("Resultado: ", resultado)
    
    
   return None  