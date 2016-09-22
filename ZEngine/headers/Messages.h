#pragma once

namespace zng {

	namespace MESSAGE {

		static unsigned short int GRAPHICS = 0x000000;
		static unsigned short int SHUTDOWN = 0x000001;

	}

	class Message {

	public:
		Message(unsigned short int type) : type(type) { };
		virtual ~Message() { };

		const inline unsigned short int getType() { return type; };

	private:
		unsigned short int type;

	};

	class GraphicsMessage : public Message {

	public:
		GraphicsMessage() : Message(MESSAGE::GRAPHICS) { };
		GraphicsMessage(int fps) : Message(MESSAGE::GRAPHICS), fps(fps) { };
		~GraphicsMessage() { };

		inline int getFps() { return fps; };

	private:
		int fps;

	};

	class ShutdownMessage : public Message {

	public:
		ShutdownMessage() : Message(MESSAGE::SHUTDOWN) { };
		~ShutdownMessage() { };

	private:

	};

}
