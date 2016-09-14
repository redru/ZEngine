#pragma once

namespace zng {

	namespace message {

		static unsigned short int GRAPHICS = 0x000000;

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
		GraphicsMessage() : Message(message::GRAPHICS) { };
		GraphicsMessage(int fps) : Message(message::GRAPHICS), fps(fps) { };
		~GraphicsMessage() { };

		inline int getFps() { return fps; };

	private:
		int fps;

	};

}
