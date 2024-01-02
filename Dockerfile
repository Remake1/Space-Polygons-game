FROM alpine
WORKDIR /app
COPY . .

# Install GCC
RUN apk add build-base
RUN apk add sfml
RUN apk add sfml-dev



RUN make build .