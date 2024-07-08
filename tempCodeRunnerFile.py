import speech_recognition as sr

r = sr.Recognizer()
print("Start speaking...")
with sr.Microphone() as source:
    r.pause_threshold = 1 #amount of time user can pause between speaking in seconds
    audio = r.listen(source)
    text = r.recognize_google(audio, language='en-in')
    print(text)
