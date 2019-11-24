#ifndef PCM_READER_FACTORY_H
#define PCM_READER_FACTORY_H

#include "pcm_stream.hpp"
#include <boost/asio/io_context.hpp>
#include <memory>
#include <string>
#include <vector>

typedef std::shared_ptr<PcmStream> PcmStreamPtr;

class StreamManager
{
public:
    StreamManager(PcmListener* pcmListener, boost::asio::io_context& ioc, const std::string& defaultSampleFormat, const std::string& defaultCodec,
                  size_t defaultReadBufferMs = 20);

    PcmStreamPtr addStream(const std::string& uri);
    void removeStream(const std::string& name);
    void start();
    void stop();
    const std::vector<PcmStreamPtr>& getStreams();
    const PcmStreamPtr getDefaultStream();
    const PcmStreamPtr getStream(const std::string& id);
    json toJson() const;

private:
    std::vector<PcmStreamPtr> streams_;
    PcmListener* pcmListener_;
    std::string sampleFormat_;
    std::string codec_;
    size_t readBufferMs_;
    boost::asio::io_context& ioc_;
};


#endif
