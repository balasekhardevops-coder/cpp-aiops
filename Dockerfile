# Runtime image
FROM debian:bookworm-slim

# Create non-root user
RUN groupadd --system appgroup && \
    useradd --system \
      --gid appgroup \
      --no-create-home \
      appuser

WORKDIR /app

# Copy compiled Release binary
COPY --chown=appuser:appgroup \
    package/bin/calculator /app/calculator

# Run as non-root
USER appuser

# Run the calculator
ENTRYPOINT ["/app/calculator"]
