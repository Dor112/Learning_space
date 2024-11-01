#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Использование: $0 <имя файла>"
  exit 1
fi

filename="$1"


if [ ! -f "$filename" ]; then
  touch "$filename"
  echo "Файл '$filename' создан."
fi


echo "Запуск netcat на порту 12345..."
nc -lk 12345 | tee -a "$filename" &
echo "Netcat запущен в фоновом режиме. Сообщения будут записываться и выводиться на экран."


while true; do
  read -p "Введите строку для записи в файл (или 'exit' для выхода): " input_string
  
  
  if [ "$input_string" == "exit" ]; then
    echo "Завершение работы скрипта."
    break
  fi

  # Запись строки в файл
  echo "$input_string" >> "$filename"
  echo "Строка записана в '$filename'."


  echo "Текущее содержимое файла '$filename':"
  while IFS= read -r line; do
    echo "$line"
  done < "$filename"
done


pkill -f "nc -lk 12345"
echo "Netcat остановлен."
